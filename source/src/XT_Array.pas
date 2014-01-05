unit XT_Array;
{=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=]
 Copyright (c) 2013, Jarl K. <Slacky> Holta || http://github.com/WarPie
 All rights reserved.
 For more info see: Copyright.txt
[=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=}
{$mode objfpc}{$H+}
{$macro on}
interface

uses
  SysUtils, XT_Types;

procedure ChrMove(const InArr:AnsiString; var DestArr:AnsiString; source, dest, size:Integer); Cdecl;
procedure IntMove(const InArr:TIntArray; var DestArr:TIntArray; source, dest, size:Integer); Cdecl;
procedure ExtMove(const InArr:TExtArray; var DestArr:TExtArray; source, dest, size:Integer); Cdecl;
procedure PtMove(const InArr:TPointArray; var DestArr:TPointArray; source, dest, size:Integer); Cdecl;



//-----------------------------------------------------------------------
implementation


procedure ChrMove(const InArr:AnsiString; var DestArr:AnsiString; source, dest, size:Integer); Cdecl;
var L:Integer;
begin
  L := Length(InArr);
  if (L = 0) or (source >= L) then Exit;
  if ((dest + size) >= Length(DestArr)) then
     size := (Length(DestArr) - dest) + 1;
  Move(InArr[source], DestArr[dest], size);
end;


procedure IntMove(const InArr:TIntArray; var DestArr:TIntArray; source, dest, size:Integer); Cdecl;
var L,bytes:Integer;
begin
  L := Length(InArr);
  if (L = 0) or (source >= L) then Exit;
  if ((dest + size) > High(DestArr)) then
     size := (High(DestArr) - dest) + 1;
  bytes := Size * SizeOf(Integer);
  Move(InArr[source], DestArr[dest], bytes);
end;


procedure ExtMove(const InArr:TExtArray; var DestArr:TExtArray; source, dest, size:Integer); Cdecl;
var L,bytes:Integer;
begin
  L := Length(InArr);
  if (L = 0) or (source >= L) then Exit;
  if ((dest + size) > High(DestArr)) then
     size := (High(DestArr) - dest) + 1;
  bytes := Size * SizeOf(Extended);
  Move(InArr[source], DestArr[dest], bytes);
end;


procedure PtMove(const InArr:TPointArray; var DestArr:TPointArray; source, dest, size:Integer); Cdecl;
var L,bytes:Integer;
begin
  L := Length(InArr);
  if (L = 0) or (source >= L) then Exit;
  if ((dest + size) > High(DestArr)) then
     size := (High(DestArr) - dest) + 1;
  bytes := Size * SizeOf(TPoint);
  Move(InArr[source], DestArr[dest], bytes);
end;



end.
