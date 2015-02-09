{=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=]
 Copyright (c) 2014, Jarl K. <Slacky> Holta || http://github.com/WarPie
 All rights reserved.
 For more info see: Copyright.txt
 
 Wrap math methods.
[=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=}
//---| math-ish |---\\
procedure _math_DistManhattan(Params: PParamArray; const Result:Pointer); cdecl; export; 
begin
  PDouble(Result)^ := DistManhattan(PPoint(Params^[1])^, PPoint(Params^[2])^);
end;

procedure _math_DistEuclidean(Params: PParamArray; const Result:Pointer); cdecl; export; 
begin
  PDouble(Result)^ := DistEuclidean(PPoint(Params^[1])^, PPoint(Params^[2])^);
end;

procedure _math_DistChebyshev(Params: PParamArray; const Result:Pointer); cdecl; export; 
begin
  PDouble(Result)^ := DistChebyshev(PPoint(Params^[1])^, PPoint(Params^[2])^);
end;

procedure _math_DistOctagonal(Params: PParamArray; const Result:Pointer); cdecl; export; 
begin
  PDouble(Result)^ := DistOctagonal(PPoint(Params^[1])^, PPoint(Params^[2])^);
end;

procedure _math_DistToLine(Params: PParamArray; const Result:Pointer); cdecl; export;
begin
  PDouble(Result)^ := DistToLine(PPoint(Params^[1])^, PPoint(Params^[2])^, PPoint(Params^[3])^);
end;

procedure _math_InCircle(Params: PParamArray; const Result:Pointer); cdecl; export;
begin
  PLongBool(Result)^ := InCircle(PPoint(Params^[1])^, PPoint(Params^[2])^, PInt32(Params^[3])^); 
end;

procedure _math_InEllipse(Params: PParamArray; const Result:Pointer); cdecl; export;
begin
  PLongBool(Result)^ := InEllipse(PPoint(Params^[1])^, PPoint(Params^[2])^, PInt32(Params^[3])^, PInt32(Params^[4])^);
end;

procedure _math_InRect(Params: PParamArray; const Result:Pointer); cdecl; export;
begin
  PLongBool(Result)^ := InRect(PPoint(Params^[1])^, PPoint(Params^[2])^, PPoint(Params^[3])^, PPoint(Params^[4])^, PPoint(Params^[5])^);
end;

procedure _math_InPoly(Params: PParamArray; const Result:Pointer); cdecl; export;
begin
  PLongBool(Result)^ := InPoly(PInt32(Params^[1])^,PInt32(Params^[2])^, PPointArray(Params^[3])^);
end;

procedure _math_InPolyR(Params: PParamArray; const Result:Pointer); cdecl; export;
begin
  PLongBool(Result)^ := InPolyR(PInt32(Params^[1])^,PInt32(Params^[2])^, PPointArray(Params^[3])^);
end;

procedure _math_InPolyW(Params: PParamArray; const Result:Pointer); cdecl; export;
begin
  PLongBool(Result)^ := InPolyW(PInt32(Params^[1])^,PInt32(Params^[2])^, PPointArray(Params^[3])^);
end;

procedure _math_DeltaAngle(Params: PParamArray; const Result:Pointer); cdecl; export;
begin
  PDouble(Result)^ := DeltaAngle(PDouble(Params^[1])^, PDouble(Params^[2])^); 
end;


//---| math |---\\
procedure _math_Cbrt(Params: PParamArray; const Result:Pointer); cdecl; export;
begin
  PSingle(Result)^ := fcbrt(PSingle(Params^[1])^);
end;

//power(x,y)
procedure _math_Power(Params: PParamArray; const Result:Pointer); cdecl; export;
begin 
  if PDouble(Params^[2])^ = 2 then
    PDouble(Result)^ := PDouble(Params^[1])^ * PDouble(Params^[1])^
  else if PDouble(Params^[2])^ = 3 then
    PDouble(Result)^ := PDouble(Params^[1])^ * PDouble(Params^[1])^ * PDouble(Params^[1])^
  else
    PDouble(Result)^ := PDouble(Params^[1])^ ** PDouble(Params^[2])^;
end;

procedure _math_PowerI(Params: PParamArray; const Result:Pointer); cdecl; export;
begin
  if PInt64(Params^[2])^ = 2 then
    PInt64(Result)^ := PInt64(Params^[1])^ * PInt64(Params^[1])^
  else if PInt64(Params^[2])^ = 3 then
    PInt64(Result)^ := PInt64(Params^[1])^ * PInt64(Params^[1])^ * PInt64(Params^[1])^
  else
    PInt64(Result)^ := PInt64(Params^[1])^ ** PInt64(Params^[2])^;
end;

//modulo(x,y)
procedure _math_Modulo(Params: PParamArray; const Result:Pointer); cdecl; export;
begin
  PDouble(Result)^ := Modulo(PDouble(Params^[1])^, PDouble(Params^[2])^);
end;

procedure _math_ModuloI(Params: PParamArray; const Result:Pointer); cdecl; export;
begin
  PInt64(Result)^ := Modulo(PInt64(Params^[1])^, PInt64(Params^[2])^);
end;

//min(x,y,z)
procedure _math_Min3f(Params: PParamArray; const Result:Pointer); cdecl; export;
begin 
  PDouble(Result)^ := Min(PDouble(Params^[1])^, PDouble(Params^[2])^, PDouble(Params^[3])^); 
end;

procedure _math_Min3i(Params: PParamArray; const Result:Pointer); cdecl; export;
begin 
  PInt64(Result)^ := Min(PInt64(Params^[1])^, PInt64(Params^[2])^, PInt64(Params^[3])^); 
end;

//max(x,y,z)
procedure _math_Max3f(Params: PParamArray; const Result:Pointer); cdecl; export;
begin 
PDouble(Result)^ := Max(PDouble(Params^[1])^, PDouble(Params^[2])^, PDouble(Params^[3])^); end;

procedure _math_Max3i(Params: PParamArray; const Result:Pointer); cdecl; export;
begin 
  PInt64(Result)^ := Max(PInt64(Params^[1])^, PInt64(Params^[2])^, PInt64(Params^[3])^); 
end;

//min(x,y)
procedure _math_Min2f(Params: PParamArray; const Result:Pointer); cdecl; export;
begin 
  PDouble(Result)^ := Min(PDouble(Params^[1])^, PDouble(Params^[2])^); 
end;

procedure _math_Min2i(Params: PParamArray; const Result:Pointer); cdecl; export;
begin 
  PInt64(Result)^ := Min(PInt64(Params^[1])^, PInt64(Params^[2])^); 
end;

//max(x,y)
procedure _math_Max2f(Params: PParamArray; const Result:Pointer); cdecl; export;
begin 
  PDouble(Result)^ := Max(PDouble(Params^[1])^, PDouble(Params^[2])^); 
end;

procedure _math_Max2i(Params: PParamArray; const Result:Pointer); cdecl; export;
begin 
  PInt64(Result)^ := Max(PInt64(Params^[1])^, PInt64(Params^[2])^); 
end;

//sign(x)
procedure _math_SignF(Params: PParamArray; const Result:Pointer); cdecl; export;
begin 
  PInt32(Result)^ := Sign(PDouble(Params^[1])^); 
end;

procedure _math_SignI(Params: PParamArray; const Result:Pointer); cdecl; export;
begin 
  PInt32(Result)^ := Sign(PInt64(Params^[1])^); 
end;

//sign(x,[e])
procedure _math_LogF(Params: PParamArray; const Result:Pointer); cdecl; export;
begin 
  if PDouble(Params^[2])^ = E then
    PDouble(Result)^ := Ln(PDouble(Params^[1])^)
  else if PDouble(Params^[2])^ = 2.0 then
    PDouble(Result)^ := Log2(PDouble(Params^[1])^)
  else if PDouble(Params^[2])^ = 10.0 then
    PDouble(Result)^ := Log10(PDouble(Params^[1])^)
  else
    PDouble(Result)^ := Logn(PDouble(Params^[1])^, PDouble(Params^[2])^); 
end;

procedure _math_LogI(Params: PParamArray; const Result:Pointer); cdecl; export;
begin
  if PDouble(Params^[2])^ = E then
    PDouble(Result)^ := Ln(PInt64(Params^[1])^)
  else if PDouble(Params^[2])^ = 2.0 then
    PDouble(Result)^ := Log2(PInt64(Params^[1])^)
  else if PDouble(Params^[2])^ = 10.0 then
    PDouble(Result)^ := Log10(PInt64(Params^[1])^)
  else
    PDouble(Result)^ := Logn(PInt64(Params^[1])^, PDouble(Params^[2])^); 
end;

//isprime(x)
procedure _math_IsPrime(Params: PParamArray; const Result:Pointer); cdecl; export;
begin 
  PLongBool(Result)^ := IsPrime(PInt32(Params^[1])^); 
end;

//nextprime(x)
procedure _math_NextPrime(Params: PParamArray; const Result:Pointer); cdecl; export;
begin 
  PInt32(Result)^ := NextPrime(PInt32(Params^[1])^); 
end;

//prevprime(x)
procedure _math_PrevPrime(Params: PParamArray; const Result:Pointer); cdecl; export;
begin 
  PInt32(Result)^ := PrevPrime(PInt32(Params^[1])^); 
end;

//NextPow2m1(x)
procedure _math_NextPow2m1(Params: PParamArray; const Result:Pointer); cdecl; export;
begin 
  PInt32(Result)^ := NextPow2m1(PInt32(Params^[1])^); 
end;



//---| random |---\\
procedure _math_Random(Params: PParamArray; const Result:Pointer); cdecl; export;
begin
  PDouble(Result)^ := Random();
end;

procedure _math_RandInt(Params: PParamArray; const Result:Pointer); cdecl; export;
begin                //lo + random(hi) - (lo - 1)
  PInt64(Result)^ := PInt64(Params^[1])^ + Random(PInt64(Params^[2])^ - PInt64(Params^[1])^ + 1);
end;

procedure _math_RandRange(Params: PParamArray; const Result:Pointer); cdecl; export;
begin                //lo + random(hi) - lo
  PInt64(Result)^ := PInt64(Params^[1])^ + Random(PInt64(Params^[2])^ - PInt64(Params^[1])^);
end;

procedure _math_Uniform(Params: PParamArray; const Result:Pointer); cdecl; export;
begin
  PDouble(Result)^ := PDouble(Params^[1])^ + (PDouble(Params^[2])^ - PDouble(Params^[1])^) * Random();
end;

procedure _math_Gauss(Params: PParamArray; const Result:Pointer); cdecl; export;
begin
  PDouble(Result)^ := Gauss(PDouble(Params^[1])^, PDouble(Params^[2])^);
end;

procedure _math_TruncedGauss(Params: PParamArray; const Result:Pointer); cdecl; export;
begin
  PDouble(Result)^ := TruncedGauss(PDouble(Params^[1])^, PDouble(Params^[2])^);
end;

procedure _math_RandPoint(Params: PParamArray; const Result:Pointer); cdecl; export;
begin
  case Random(2) of
    0: PPoint(Result)^.x := Round(PPoint(Params^[1])^.x + TruncedGauss(0,PInt32(Params^[2])^));
    1: PPoint(Result)^.x := Round(PPoint(Params^[1])^.x - TruncedGauss(0,PInt32(Params^[2])^));
  end;
  case Random(2) of
    0: PPoint(Result)^.y := Round(PPoint(Params^[1])^.y + TruncedGauss(0,PInt32(Params^[2])^));
    1: PPoint(Result)^.y := Round(PPoint(Params^[1])^.y - TruncedGauss(0,PInt32(Params^[2])^));
  end;
end;

procedure _math_RandPointInBox(Params: PParamArray; const Result:Pointer); cdecl; export;
var B:TBox;
begin
  B := PBox(Params^[1])^;
  case Random(2) of
    0: PPoint(Result)^.x := Round(((B.x2+B.x1) / 2) + TruncedGauss(0,(B.x2-B.x1+1)/2));
    1: PPoint(Result)^.x := Round(((B.x2+B.x1) / 2) - TruncedGauss(0,(B.x2-B.x1+1)/2));
  end;
  case Random(2) of
    0: PPoint(Result)^.y := Round(((B.y2+B.y1) / 2) + TruncedGauss(0,(B.y2-B.y1+1)/2));
    1: PPoint(Result)^.y := Round(((B.y2+B.y1) / 2) - TruncedGauss(0,(B.y2-B.y1+1)/2));
  end;
end;