{=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=]
 Copyright (c) 2014, Jarl K. <Slacky> Holta || http://github.com/WarPie
 All rights reserved.
 For more info see: Copyright.txt
 
 Exports math methods.
[=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=}
AddMethod(@_math_DistManhattan,	'function SimbaExt.DistManhattan(pt1,pt2: TPoint): Double; native;');
AddMethod(@_math_DistEuclidean,	'function SimbaExt.DistEuclidean(pt1,pt2: TPoint): Double; native;');
AddMethod(@_math_DistChebyshev,	'function SimbaExt.DistChebyshev(pt1,pt2: TPoint): Double; native;');
AddMethod(@_math_DistOctagonal,	'function SimbaExt.DistOctagonal(pt1,pt2: TPoint): Double; native;');
AddMethod(@_math_DistToLine,	'function SimbaExt.DistToLine(Pt, sA, sB: TPoint): Double; native;');
AddMethod(@_math_InCircle,	'function SimbaExt.InCircle(const Pt, Center: TPoint; Radius: Integer): LongBool; native;');
AddMethod(@_math_InEllipse,	'function SimbaExt.InEllipse(const Pt,Center:TPoint; YRad, XRad: Integer): LongBool; native;');
AddMethod(@_math_InRect,	'function SimbaExt.InRect(const Pt:TPoint; const A,B,C,D:TPoint): LongBool; native;');
AddMethod(@_math_InPoly,	'function SimbaExt.InPoly(x,y:Integer; const Poly:TPointArray): LongBool; native;');
AddMethod(@_math_InPolyR,	'function SimbaExt.InPolyR(x,y:Integer; const Poly:TPointArray): LongBool; native;');
AddMethod(@_math_InPolyW,	'function SimbaExt.InPolyW(x,y:Integer; const Poly:TPointArray): LongBool; native;');
AddMethod(@_math_DeltaAngle,	'function SimbaExt.DeltaAngle(DegA,DegB:Double): Double; native;');

//mostly math
AddMethod(@_math_Cbrt,		'function SimbaExt.Cbrt(x: Single): Single; native;');
AddMethod(@_math_Power,		'function SimbaExt.Power(x,y: Double): Single; native;');
AddMethod(@_math_PowerI,	'function SimbaExt.Power(x,y: Int64): Int64; overload; native;');
AddMethod(@_math_Modulo,	'function SimbaExt.Modulo(X,Y:Double): Double; native;');
AddMethod(@_math_ModuloI,	'function SimbaExt.Modulo(X,Y:Int64): Int64; overload; native;');
AddMethod(@_math_Min2f,		'function SimbaExt.Min(X,Y:Double): Double; native;');
AddMethod(@_math_Min2i,		'function SimbaExt.Min(X,Y:Int64): Int64; overload; native;');
AddMethod(@_math_Min3f,		'function SimbaExt.Min(X,Y,Z:Double): Double; overload; native;');
AddMethod(@_math_Min3i,		'function SimbaExt.Min(X,Y,Z:Int64): Int64; overload; native;');
AddMethod(@_math_Max2f,		'function SimbaExt.Max(X,Y:Double): Double; native;');
AddMethod(@_math_Max2i,		'function SimbaExt.Max(X,Y:Int64): Int64; overload; native;');
AddMethod(@_math_Max3f,		'function SimbaExt.Max(X,Y,Z:Double): Double; overload; native;');
AddMethod(@_math_Max3i,		'function SimbaExt.Max(X,Y,Z:Int64): Int64; overload; native;');
AddMethod(@_math_SignI,		'function SimbaExt.Sign(X:Int64): Int32; native;');
AddMethod(@_math_SignF,		'function SimbaExt.Sign(X:Double): Int32; overload; native;');
AddMethod(@_math_LogI,		'function SimbaExt.Log(X:Int64; Base:Double=2.718281828459): Double; native;');
AddMethod(@_math_LogF,		'function SimbaExt.Log(X:Double; Base:Double=2.718281828459): Double; overload; native;');
AddMethod(@_math_IsPrime,	'function SimbaExt.IsPrime(n:Int32): LongBool; native;');
AddMethod(@_math_NextPrime,	'function SimbaExt.NextPrime(n:Int32): Int32; native;');
AddMethod(@_math_PrevPrime,	'function SimbaExt.PrevPrime(n:Int32): Int32; native;');
AddMethod(@_math_NextPow2m1,	'function SimbaExt.NextPow2m1(n:Int32): Int32; native;');

//mostly random (related)
AddMethod(@_math_Random,        'function SimbaExt.Random(): Double; native;');
AddMethod(@_math_RandInt,       'function SimbaExt.RandInt(lo,hi:Int64): Int64; native;');
AddMethod(@_math_RandRange,     'function SimbaExt.RandRange(lo,hi:Int64): Int64; native;');
AddMethod(@_math_Uniform,       'function SimbaExt.Uniform(lo,hi:Double): Double; native;');
AddMethod(@_math_Gauss,         'function SimbaExt.Gauss(mu,sigma:Double): Double; native;');
AddMethod(@_math_TruncedGauss,  'function SimbaExt.TruncedGauss(lo,hi:Double): Double; native;');
AddMethod(@_math_RandPoint,     'function SimbaExt.RandomPoint(pt:TPoint; radius:Int32): TPoint; native;');
AddMethod(@_math_RandPointInBox,'function SimbaExt.RandomPoint(b: TBox): TPoint; overload; native;');