{=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=]
 Copyright (c) 2013, Jarl K. <Slacky> Holta || http://github.com/WarPie
 All rights reserved.
 For more info see: Copyright.txt

 Find the N-minimum or N-maximum values in the matrix, and return their indices.
[=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=}

{$define ArgMultiBody :=
 H := High(Mat);
 if (H = -1) then NewException(exEmptyMatrix);
 W := High(Mat[0]);

 Heap := THeapq.Create(HiLo);
 width := w + 1;
 case HiLo of
   True:
     for y:=0 to H do
       for x:=0 to W do
         if (Heap.Size < count) or (mat[y,x] > Heap[0].value) then
         begin
           if (Heap.Size = count) then Heap.Pop();
           Heap.Push(mat[y,x], y*width+x);
         end;
   False:
     for y:=0 to H do
       for x:=0 to W do
         if (Heap.Size < count) or (mat[y,x] < Heap[0].value) then
         begin
           if (Heap.Size = count) then Heap.Pop();
           Heap.Push(mat[y,x], y*width+x);
         end;
 end;

 SetLength(Result, Heap.Size);
 for i:=0 to Heap.Size-1 do begin
   Result[i].y := Heap[i].extra div Width;
   Result[i].x := Heap[i].extra - Result[i].y * Width;
 end;

 Heap.Destroy;
}

function ArgMulti(Mat:T2DByteArray; Count:Int32; HiLo:Boolean): TPointArray; overload;
type
  THeapq = specialize HeapQueue<Byte>;
var
  W,H,i,y,x,width: Int32;
  heap:THeapq;
begin
  ArgMultiBody
end;

function ArgMulti(Mat:T2DIntArray; Count:Int32; HiLo:Boolean): TPointArray; overload;
type
  THeapq = specialize HeapQueue<Int32>;
var
  W,H,i,y,x,width: Int32;
  heap:THeapq;
begin
  ArgMultiBody
end;

function ArgMulti(Mat:T2DExtArray; Count:Int32; HiLo:Boolean): TPointArray; overload;
type
  THeapq = specialize HeapQueue<Extended>;
var
  W,H,i,y,x,width: Int32;
  heap:THeapq;
begin
  ArgMultiBody
end;

function ArgMulti(Mat:T2DDoubleArray; Count:Int32; HiLo:Boolean): TPointArray; overload;
type
  THeapq = specialize HeapQueue<Double>;
var
  W,H,i,y,x,width: Int32;
  heap:THeapq;
begin
  ArgMultiBody
end;


function ArgMulti(Mat:T2DFloatArray; Count:Int32; HiLo:Boolean): TPointArray; overload;
type
  THeapq = specialize HeapQueue<Single>;
var
  W,H,i,y,x,width: Int32;
  heap:THeapq;
begin
  ArgMultiBody
end;



