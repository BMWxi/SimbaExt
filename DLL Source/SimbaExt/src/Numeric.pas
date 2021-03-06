Unit Numeric;
{=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=]
 Copyright (c) 2013, Jarl K. <Slacky> Holta || http://github.com/WarPie
 All rights reserved.
 For more info see: Copyright.txt
[=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=}
{$mode objfpc}{$H+}
{$macro on}
{$inline on}

interface
uses
  CoreTypes, Math, SysUtils;

function SumFPtr(Ptr:PChar; Size:UInt8; Len:LongInt): Extended; cdecl;
function SumPtr(Ptr:PChar; Size:UInt8; Len:LongInt; Signed:Boolean): Int64; cdecl;

function SumTBA(const Arr: CoreTypes.TByteArray): Int64; Inline;
function SumTIA(const Arr: TIntArray): Int64; Inline; 
function SumTEA(const Arr: TExtArray): Extended; Inline; 

procedure MinMaxFPtr(Ptr:PChar; Size:UInt8; Len:LongInt; var Min,Max:Extended); cdecl;
procedure MinMaxPtr(Ptr:PChar; Size:UInt8; Len:LongInt; Signed:Boolean; var Min,Max:Int64); cdecl;

procedure MinMaxTBA(const Arr: CoreTypes.TByteArray; var Min:Byte; var Max: Byte); Inline;
procedure MinMaxTIA(const Arr: TIntArray; var Min:Integer; var Max: Integer); Inline; 
procedure MinMaxTEA(const Arr: TExtArray; var Min:Extended; var Max: Extended); Inline; 


function TIACombinations(const Arr: TIntArray; Seq:Integer): T2DIntArray; 
function TEACombinations(const Arr: TExtArray; Seq:Integer): T2DExtArray; 
function TIAMatches(const Arr1, Arr2:TIntArray; InPercent, Inversed:Boolean): Int32; 
function LogscaleTIA(const Freq:TIntArray; Scale: Integer): TIntArray; 


//--------------------------------------------------
implementation


{*
  Returns the sum of a normal floating point type array.
*}
function SumFPtr(Ptr:PChar; Size:UInt8; Len:LongInt): Extended; cdecl;
var l:Int32;
begin
  Result := 0;
  l := UInt32(ptr)+(len*size);
  while (UInt32(ptr) < l) do begin
    case size of
      4 : Result := Result + PFloat32(Ptr)^;
      8 : Result := Result + PFloat64(Ptr)^;
      10: Result := Result + PFloat80(Ptr)^;
    end;
    Inc(ptr,size);
  end;
end;


{*
  Returns the sum of a normal int type array.
*}
function SumPtr(Ptr:PChar; Size:UInt8; Len:LongInt; Signed:Boolean): Int64; cdecl;
var l:Int32;
begin
  Result := 0;
  l := UInt32(ptr)+(len*size);

  case signed of
  True:
    while (UInt32(ptr) < l) do begin
      case size of
        1 : Result := Result + PUInt8(Ptr)^;
        2 : Result := Result + PUInt16(Ptr)^;
        4 : Result := Result + PUInt32(Ptr)^;
        8 : Result := Result + PUInt64(Ptr)^;
      end;
      Inc(ptr,size);
    end;
  False:
    while (UInt32(ptr) < l) do begin
      case size of
        1 : Result := Result + PInt8(Ptr)^;
        2 : Result := Result + PInt16(Ptr)^;
        4 : Result := Result + PInt32(Ptr)^;
        8 : Result := Result + PInt64(Ptr)^;
      end;
      Inc(ptr,size);
    end;
  end;
end;


{*
  Sum of a TBA.
*}
function SumTBA(const Arr: CoreTypes.TByteArray): Int64; Inline;
var i:Integer;
begin
  Result := 0;
  for i:=Low(Arr) to High(Arr) do
    Result := Result + Arr[i];
end;


{*
  Sum of a TIA.
*}
function SumTIA(const Arr: TIntArray): Int64; Inline; 
var i:Integer;
begin
  Result := 0;
  for i:=Low(Arr) to High(Arr) do
    Result := Result + Arr[i];
end;


{*
  Sum of a TEA.
*}
function SumTEA(const Arr: TExtArray): Extended; Inline; 
var i:Integer;
begin
  Result := 0.0;
  for i:=Low(Arr) to High(Arr) do
    Result := Result + Arr[i];
end;



{*
  Finds the minimum and maximum of a single-, double-, or extended array.
*}
procedure MinMaxFPtr(Ptr:PChar; Size:UInt8; Len:LongInt; var Min,Max:Extended);  cdecl;
var l:Int32;
begin
  l := UInt32(ptr)+(len*size);
  case size of
    4 :begin Min := PFloat32(Ptr)^; Max := Min; end;
    8 :begin Min := PFloat64(Ptr)^; Max := Min; end;
    10:begin Min := PFloat80(Ptr)^; Max := Min; end;
  end;
  while (UInt32(ptr) < l) do begin
    case size of
      4 : if PFloat32(Ptr)^ < Min then        Min := PFloat32(Ptr)^
          else if PFloat32(Ptr)^ > Max then   Max := PFloat32(Ptr)^;
      8 : if PFloat64(Ptr)^ < Min then        Min := PFloat64(Ptr)^
          else if PFloat64(Ptr)^ > Max then   Max := PFloat64(Ptr)^;
      10: if PFloat80(Ptr)^ < Min then        Min := PFloat80(Ptr)^
          else if PFloat80(Ptr)^ > Max then   Max := PFloat80(Ptr)^;
    end;
    Inc(ptr,size);
  end;
end;


{*
  Finds the minimum and maximum of any normal integer typed array.
*}
procedure MinMaxPtr(Ptr:PChar; Size:UInt8; Len:LongInt; Signed:Boolean; var Min,Max:Int64); cdecl;
var l:Int32; tmp:Int64;
begin
  l := UInt32(ptr)+(len*size);
  if signed then
    case size of
      1 :begin Min := PInt8(Ptr)^;  Max := Min; end;
      2 :begin Min := PInt16(Ptr)^; Max := Min; end;
      4 :begin Min := PInt32(Ptr)^; Max := Min; end;
      8 :begin Min := PInt64(Ptr)^; Max := Min; end;
    end
  else
    case size of
      1 :begin Min := PUInt8(Ptr)^;  Max := Min; end;
      2 :begin Min := PUInt16(Ptr)^; Max := Min; end;
      4 :begin Min := PUInt32(Ptr)^; Max := Min; end;
      8 :begin Min := PUInt64(Ptr)^; Max := Min; end;
    end;

  case signed of
  True:
    while (UInt32(ptr) < l) do begin
      case size of
        1: tmp := PUInt8(Ptr)^;
        2: tmp := PUInt16(Ptr)^;
        4: tmp := PUInt32(Ptr)^;
        8: tmp := PUInt64(Ptr)^;
      end;
      if (tmp < Min) then Min := tmp else if (tmp > Max) then Max := tmp;
      Inc(ptr,size);
    end;
  False:
    while (UInt32(ptr) < l) do begin
      case size of
        1: tmp := PUInt8(Ptr)^;
        2: tmp := PUInt16(Ptr)^;
        4: tmp := PUInt32(Ptr)^;
        8: tmp := PUInt64(Ptr)^;
      end;
      if (tmp < Min) then Min := tmp else if (tmp > Max) then Max := tmp;
      Inc(ptr,size);
    end;
  end;
end; 


{*
  Finds the minimum and maximum of a TBA.
*}
procedure MinMaxTBA(const Arr: CoreTypes.TByteArray; var Min:Byte; var Max: Byte); Inline;
var i:Int32;
begin
  Min := Arr[0];
  Max := Arr[0];
  for i:=Low(Arr) to High(Arr) do
    if (Arr[i] < Min) then Min := Arr[i] else if (Arr[i] > Max) then Max := Arr[i];
end;


{*
  Finds the minimum and maximum of a TIA.
*}
procedure MinMaxTIA(const Arr: TIntArray; var Min:Integer; var Max: Integer); Inline; 
var i:Int32;
begin
  Min := Arr[0];
  Max := Arr[0];
  for i:=Low(Arr) to High(Arr) do
    if (Arr[i] < Min) then Min := Arr[i] else if (Arr[i] > Max) then Max := Arr[i];
end;


{*
  Finds the minimum and maximum of a TEA.
*}
procedure MinMaxTEA(const Arr: TExtArray; var Min:Extended; var Max: Extended); Inline; 
var i:Integer;
begin
  Min := Arr[0];
  Max := Arr[0];
  for i:=Low(Arr) to High(Arr) do
    if (Arr[i] < Min) then Min := Arr[i] else if (Arr[i] > Max) then Max := Arr[i];
end;




{~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]
[--|  OLDER STUFF  |-----------------------------------------------------------------]
[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~}


{*
  Combinations of size `seq` from given TIA `arr`.
*}
function TIACombinations(const Arr:TIntArray; Seq:Integer): T2DIntArray; 
var
  n,h,i,j: Integer;
  indices: TIntArray;
  breakout: Boolean;
begin
  n := Length(arr);
  if seq > n then Exit;
  SetLength(indices, seq);
  for i:=0 to (seq-1) do indices[i] := i;
  SetLength(Result, 1, Seq);
  for i:=0 to (seq-1) do Result[0][i] := arr[i];
  while True do
  begin
    breakout := True;
    for i:=(Seq-1) downto 0 do
      if (indices[i] <> (i + n - Seq)) then begin
        breakout := False;
        Break;
      end;
    if breakout then Exit;
    Indices[i] := Indices[i]+1;
    for j:=i+1 to Seq-1 do
      Indices[j] := (Indices[j-1] + 1);
    h := Length(Result);
    SetLength(Result, h+1);
    SetLength(Result[h], Seq);
    for i:=0 to Seq-1 do
      Result[h][i] := Arr[Indices[i]];
  end;
  SetLength(Indices, 0);
end;


{*
  Combinations of size `seq` from given TEA `arr`.
*}
function TEACombinations(const Arr: TExtArray; Seq:Integer): T2DExtArray; 
var
  n,h,i,j: Integer;
  indices: TIntArray;
  breakout: Boolean;
begin
  n := Length(arr);
  if seq > n then Exit;
  SetLength(Indices, seq);
  for i:=0 to (seq-1) do Indices[i] := i;
  SetLength(Result, 1, Seq);
  for i:=0 to (seq-1) do Result[0][i] := Arr[i];
  while True do
  begin
    breakout := True;
    for i:=(Seq-1) downto 0 do
      if (Indices[i] <> (i + n - Seq)) then begin
        Breakout := False;
        Break;
      end;
    if Breakout then Exit;
    Indices[i] := Indices[i]+1;
    for j:=i+1 to Seq-1 do
      Indices[j] := (Indices[j-1] + 1);
    h := Length(Result);
    SetLength(Result, h+1);
    SetLength(Result[h], Seq);
    for i:=0 to Seq-1 do
      Result[h][i] := Arr[Indices[i]];
  end;
  SetLength(Indices, 0);
end;

{*
  Finds the amount of different indices, by comparing each index in "Arr1" to each index in "Arr2".
*}
function TIAMatches(const Arr1, Arr2:TIntArray; InPercent, Inversed:Boolean): Int32; 
var H,i:integer;
begin
  H := Min(High(Arr1), High(Arr2));
  Result := Abs(High(Arr1) - High(Arr2));
  for I:=0 to H do
    if (Arr1[I] <> Arr2[I]) then
      Inc(Result);
      
  if InPercent then begin
    H := Max(High(Arr1), High(Arr2));
    Result := Trunc((Result / H) * 100);
  end;
  
  if Inversed then begin
    case InPercent of 
      True : Result := (100-Result);
      False: Result := (Max(High(Arr1), High(Arr2)) - Result);
    end;
  end;
end;


{*
 Given a TIA with a range of numbers it scales each element in a logarithmic pattern:
 EG:
 > Freq := [0,1,2,3,4]
 > Scale := 2;
 > Result := [0, 1,1, 2,2,2,2, 3,3,3,3,3,3,3,3, ...];
*}
function LogscaleTIA(const Freq:TIntArray; Scale: Integer): TIntArray; 
var
  Size,i,j,H: Integer;
  step,L:Integer;
begin
  H := High(Freq);
  if H = -1 then Exit;
  if (Scale <= 1) or (H = 0) then
  begin
    Result := Copy(Freq);
    Exit;
  end;
  Step := 1;
  SetLength(Result, Step);
  Size := 1;
  L := 0;
  i := 0;
  for i:=0 to H do
  begin 
    for j:=0 to Size-1 do
    begin 
      if L >= Step then begin
        step := step+step;
        SetLength(Result, step);
      end;
      Result[L] := Freq[i];
      Inc(L);
    end;
    Size := Size * Scale; 
  end;
  SetLength(Result, L);
end;


end.






