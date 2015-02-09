{=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=]
 Copyright (c) 2014, Jarl K. <Slacky> Holta || http://github.com/WarPie
 All rights reserved.
 For more info see: Copyright.txt
 
 Wrap imaging methods (Imaging.pas)
[=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=}
procedure exp_ImGrayscale(var SE:Pointer; const ImgArr:T2DIntArray; var Dest:T2DIntArray); cdecl;
begin
  ImGrayscale(ImgArr, Dest);
end;

function exp_GaussKernel(var SE:Pointer; KernelRadius:Integer; Sigma:Single): T2DFloatArray; cdecl;
begin
  Result := GaussKernel(KernelRadius, Sigma);
end;

procedure exp_ImBlur(var SE:Pointer; const ImgArr:T2DIntArray; var Dest:T2DIntArray; Radius:Integer); cdecl;
begin
  ImBlur(ImgArr, Dest, Radius);
end;

function exp_ImMedianBlur(var SE:Pointer; const ImgArr: T2DIntArray; Radius:Int32): T2DIntArray; cdecl;
begin
  Result := ImMedianBlur(ImgArr, Radius);
end;

function exp_ImBrighten(var SE:Pointer; const ImgArr:T2DIntArray; Amount:Extended): T2DIntArray; cdecl;
begin
  Result := ImBrighten(ImgArr, Amount);
end;

procedure exp_ImThreshold(var SE:Pointer; var ImgArr:T2DIntArray; Threshold:Byte; Alpha, Beta:Int32); cdecl;
begin
  ImThreshold(ImgArr, Threshold, Alpha, Beta);
end;

procedure exp_ImThresholdAdaptive(var SE:Pointer; var ImgArr:T2DIntArray; Alpha, Beta: Int32; Method:EThreshAlgo; C:Int32); cdecl;
begin
  ImThresholdAdaptive(ImgArr, Alpha, Beta, Method, C);
end;

function exp_ImFindContours(var SE:Pointer; const ImgArr: T2DIntArray; Threshold: Int32): T2DPointArray; cdecl;
begin
  Result := ImFindContours(ImgArr, Threshold);
end;

function exp_ImCEdges(var SE:Pointer; const ImgArr: T2DIntArray; MinDiff: Int32): TPointArray; cdecl;
begin
  Result := ImCEdges(ImgArr, MinDiff);
end;

function exp_ImSobel(var SE:Pointer; const ImgArr: T2DIntArray; Axis:Int8): T2DIntArray; cdecl;
begin
  if Axis in [0,1] then
    Result := ImSobel(ImgArr,axis)
  else
    Result := ImSobel(ImgArr);
end;

function exp_ImConvolve(var SE:Pointer; const ImgArr:T2DIntArray; const Mask:T2DFloatArray): T2DIntArray; cdecl;
begin
  Result := ImConvolve(ImgArr, Mask);
end;

procedure exp_ImGaussBlur(var SE:Pointer; const ImgArr:T2DIntArray; var Dest:T2DIntArray; Radius:Int32; Sigma:Single); cdecl;
begin
  ImGaussBlur(ImgArr, Dest, Radius, Sigma);
end;

function exp_ImBlend(var SE:Pointer; const ImgArr1,ImgArr2: T2DIntArray; Alpha: Single): T2DIntArray; cdecl;
begin
  Result := ImBlend(ImgArr1, ImgArr2, Alpha);
end;

function exp_ImCompareAt(var SE:Pointer; const large,small:T2DIntArray; pt:TPoint; tol:Int32): Single; cdecl;
begin
  Result := ImCompareAt(large, small, pt, tol);
end;

procedure exp_ImResize(var SE:Pointer; var ImgArr:T2DIntArray; NewW, NewH: Integer; Method:EResizeAlgo); Cdecl;
begin
  ImResize(ImgArr, NewW, NewH, Method);
end;

function exp_ImSample(var SE:Pointer; ImgArr:T2DIntArray; SampleScale:Int32): T2DIntArray; Cdecl;
begin
  Result := ImSample(ImgArr, SampleScale);
end;

function exp_ImRotate(var SE:Pointer; const ImgArr:T2DIntArray; Angle:Single; Expand:LongBool; Bilinear:LongBool=True): T2DIntArray; Cdecl;
begin
  Result := ImRotate(ImgArr, Angle, Expand, Bilinear);
end;