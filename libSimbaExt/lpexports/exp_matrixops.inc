{=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=]
 Copyright (c) 2014, Jarl K. <Slacky> Holta || http://github.com/WarPie
 All rights reserved.
 For more info see: Copyright.txt
 
 Exports matrix operations (MatrixOps.pas)
[=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=}
AddMethod(@exp_FillMatB, 'procedure SimbaExt.Fill(var Mat:TByteMatrix; Fill:UInt8);');
AddMethod(@exp_FillMatI, 'procedure SimbaExt.Fill(var Mat:TIntMatrix; Fill:Int32); overload;');
AddMethod(@exp_FillMatF, 'procedure SimbaExt.Fill(var Mat:TFloatMatrix; Fill:Single); overload;');
AddMethod(@exp_FillMatD, 'procedure SimbaExt.Fill(var Mat:TDoubleMatrix; Fill:Double); overload;');
AddMethod(@exp_FillMatE, 'procedure SimbaExt.Fill(var Mat:TExtMatrix; Fill:Extended); overload;');
AddMethod(@exp_FillMatExB, 'procedure SimbaExt.Fill(var Mat:TByteMatrix; Area:TBox; Fill:UInt8); overload;');
AddMethod(@exp_FillMatExI, 'procedure SimbaExt.Fill(var Mat:TIntMatrix; Area:TBox; Fill:Int32); overload;');
AddMethod(@exp_FillMatExF, 'procedure SimbaExt.Fill(var Mat:TFloatMatrix; Area:TBox; Fill:Single); overload;');
AddMethod(@exp_FillMatExD, 'procedure SimbaExt.Fill(var Mat:TDoubleMatrix; Area:TBox; Fill:Double); overload;');
AddMethod(@exp_FillMatExE, 'procedure SimbaExt.Fill(var Mat:TExtMatrix; Area:TBox; Fill:Extended); overload;');

AddMethod(@exp_IndicesB, 'function SimbaExt.Indices(const Mat:TByteMatrix; Value: Byte; const Comparator:EComparator): TPointArray;');
AddMethod(@exp_IndicesI, 'function SimbaExt.Indices(const Mat:TIntMatrix; Value: Integer; const Comparator:EComparator): TPointArray; overload;');
AddMethod(@exp_IndicesE, 'function SimbaExt.Indices(const Mat:TExtMatrix; Value: Extended; const Comparator:EComparator): TPointArray; overload;');
AddMethod(@exp_IndicesD, 'function SimbaExt.Indices(const Mat:TDoubleMatrix; Value: Double; const Comparator:EComparator): TPointArray; overload;');
AddMethod(@exp_IndicesF, 'function SimbaExt.Indices(const Mat:TFloatMatrix; Value: Single; const Comparator:EComparator): TPointArray; overload;');
AddMethod(@exp_IndicesExB, 'function SimbaExt.Indices(const Mat:TByteMatrix; B:TBox; Value: Integer; const Comparator:EComparator): TPointArray; overload;');
AddMethod(@exp_IndicesExI, 'function SimbaExt.Indices(const Mat:TIntMatrix; B:TBox; Value: Integer; const Comparator:EComparator): TPointArray; overload;');
AddMethod(@exp_IndicesExE, 'function SimbaExt.Indices(const Mat:TExtMatrix; B:TBox; Value: Extended; const Comparator:EComparator): TPointArray; overload;');
AddMethod(@exp_IndicesExD, 'function SimbaExt.Indices(const Mat:TDoubleMatrix; B:TBox; Value: Double; const Comparator:EComparator): TPointArray; overload;');
AddMethod(@exp_IndicesExF, 'function SimbaExt.Indices(const Mat:TFloatMatrix; B:TBox; Value: Single; const Comparator:EComparator): TPointArray; overload;');

AddMethod(@exp_MinMaxB, 'procedure SimbaExt.MinMax(Mat:TByteMatrix; var Min, Max:Byte);  overload;');      //overloads "statistics.pas" MinMax
AddMethod(@exp_MinMaxI, 'procedure SimbaExt.MinMax(Mat:TIntMatrix; var Min, Max:Integer); overload;');
AddMethod(@exp_MinMaxE, 'procedure SimbaExt.MinMax(Mat:TExtMatrix; var Min, Max:Extended); overload;');
AddMethod(@exp_MinMaxD, 'procedure SimbaExt.MinMax(Mat:TDoubleMatrix; var Min, Max:Double); overload;');
AddMethod(@exp_MinMaxF, 'procedure SimbaExt.MinMax(Mat:TFloatMatrix; var Min, Max:Single); overload;');

AddMethod(@exp_MinB, 'function SimbaExt.Min(Mat:TByteMatrix): Byte;  overload;');                         //overloads "statistics.pas" MinMax
AddMethod(@exp_MinI, 'function SimbaExt.Min(Mat:TIntMatrix): Int32; overload;');
AddMethod(@exp_MinF, 'function SimbaExt.Min(Mat:TFloatMatrix): Single; overload;');
AddMethod(@exp_MinD, 'function SimbaExt.Min(Mat:TDoubleMatrix): Double; overload;');
AddMethod(@exp_MinE, 'function SimbaExt.Min(Mat:TExtMatrix): Extended; overload;');

AddMethod(@exp_MaxB, 'function SimbaExt.Max(Mat:TByteMatrix): Byte;  overload;');                         //overloads "statistics.pas" MinMax
AddMethod(@exp_MaxI, 'function SimbaExt.Max(Mat:TIntMatrix): Int32; overload;');
AddMethod(@exp_MaxF, 'function SimbaExt.Max(Mat:TFloatMatrix): Single; overload;');
AddMethod(@exp_MaxD, 'function SimbaExt.Max(Mat:TDoubleMatrix): Double; overload;');
AddMethod(@exp_MaxE, 'function SimbaExt.Max(Mat:TExtMatrix): Extended; overload;');

AddMethod(@exp_ArgMaxB, 'function SimbaExt.ArgMax(Mat:TByteMatrix): TPoint;');
AddMethod(@exp_ArgMaxI, 'function SimbaExt.ArgMax(Mat:TIntMatrix): TPoint; overload;');
AddMethod(@exp_ArgMaxE, 'function SimbaExt.ArgMax(Mat:TExtMatrix): TPoint; overload;');
AddMethod(@exp_ArgMaxD, 'function SimbaExt.ArgMax(Mat:TDoubleMatrix): TPoint; overload;');
AddMethod(@exp_ArgMaxF, 'function SimbaExt.ArgMax(Mat:TFloatMatrix): TPoint; overload;');
AddMethod(@exp_ArgMinB, 'function SimbaExt.ArgMin(Mat:TByteMatrix): TPoint; overload;');
AddMethod(@exp_ArgMinI, 'function SimbaExt.ArgMin(Mat:TIntMatrix): TPoint; overload;');
AddMethod(@exp_ArgMinE, 'function SimbaExt.ArgMin(Mat:TExtMatrix): TPoint; overload;');
AddMethod(@exp_ArgMinD, 'function SimbaExt.ArgMin(Mat:TDoubleMatrix): TPoint; overload;');
AddMethod(@exp_ArgMinF, 'function SimbaExt.ArgMin(Mat:TFloatMatrix): TPoint; overload;');

AddMethod(@exp_ArgMaxExB, 'function SimbaExt.ArgMax(Mat:TByteMatrix; B:TBox): TPoint; overload;');
AddMethod(@exp_ArgMaxExI, 'function SimbaExt.ArgMax(Mat:TIntMatrix; B:TBox): TPoint; overload;');
AddMethod(@exp_ArgMaxExE, 'function SimbaExt.ArgMax(Mat:TExtMatrix; B:TBox): TPoint; overload;');
AddMethod(@exp_ArgMaxExD, 'function SimbaExt.ArgMax(Mat:TDoubleMatrix; B:TBox): TPoint; overload;');
AddMethod(@exp_ArgMaxExF, 'function SimbaExt.ArgMax(Mat:TFloatMatrix; B:TBox): TPoint; overload;');
AddMethod(@exp_ArgMinExB, 'function SimbaExt.ArgMin(Mat:TByteMatrix; B:TBox): TPoint; overload;');
AddMethod(@exp_ArgMinExI, 'function SimbaExt.ArgMin(Mat:TIntMatrix; B:TBox): TPoint; overload;');
AddMethod(@exp_ArgMinExE, 'function SimbaExt.ArgMin(Mat:TExtMatrix; B:TBox): TPoint; overload;');
AddMethod(@exp_ArgMinExD, 'function SimbaExt.ArgMin(Mat:TDoubleMatrix; B:TBox): TPoint; overload;');
AddMethod(@exp_ArgMinExF, 'function SimbaExt.ArgMin(Mat:TFloatMatrix; B:TBox): TPoint; overload;');

AddMethod(@exp_VarMultiB, 'function SimbaExt.VarMulti(const Mat:TByteMatrix; Count: Int32; HiLo:LongBool):TByteArray;');
AddMethod(@exp_VarMultiI, 'function SimbaExt.VarMulti(const Mat:TIntMatrix; Count: Int32; HiLo:LongBool): TIntArray; overload;');
AddMethod(@exp_VarMultiE, 'function SimbaExt.VarMulti(const Mat:TExtMatrix; Count: Int32; HiLo:LongBool): TExtArray; overload;');
AddMethod(@exp_VarMultiD, 'function SimbaExt.VarMulti(const Mat:TDoubleMatrix; Count: Int32; HiLo:LongBool): TDoubleArray; overload;');
AddMethod(@exp_VarMultiF, 'function SimbaExt.VarMulti(const Mat:TFloatMatrix; Count: Int32; HiLo:LongBool): TFloatArray; overload;');

AddMethod(@exp_ArgMultiB, 'function SimbaExt.ArgMulti(const Mat:TByteMatrix; Count: Int32; HiLo:LongBool): TPointArray;');
AddMethod(@exp_ArgMultiI, 'function SimbaExt.ArgMulti(const Mat:TIntMatrix; Count: Int32; HiLo:LongBool): TPointArray; overload;');
AddMethod(@exp_ArgMultiE, 'function SimbaExt.ArgMulti(const Mat:TExtMatrix; Count: Int32; HiLo:LongBool): TPointArray; overload;');
AddMethod(@exp_ArgMultiD, 'function SimbaExt.ArgMulti(const Mat:TDoubleMatrix; Count: Int32; HiLo:LongBool): TPointArray; overload;');
AddMethod(@exp_ArgMultiF, 'function SimbaExt.ArgMulti(const Mat:TFloatMatrix; Count: Int32; HiLo:LongBool): TPointArray; overload;');

AddMethod(@exp_GetValuesB, 'function SimbaExt.GetData(const Mat:TByteMatrix; const indices:TPointArray): TByteArray;');
AddMethod(@exp_GetValuesI, 'function SimbaExt.GetData(const Mat:TIntMatrix; const indices:TPointArray): TIntArray; overload;');
AddMethod(@exp_GetValuesF, 'function SimbaExt.GetData(const Mat:TFloatMatrix; const indices:TPointArray): TFloatArray; overload;');
AddMethod(@exp_GetValuesD, 'function SimbaExt.GetData(const Mat:TDoubleMatrix; const indices:TPointArray): TDoubleArray; overload;');
AddMethod(@exp_GetValuesE, 'function SimbaExt.GetData(const Mat:TExtMatrix; const indices:TPointArray): TExtArray; overload;');

AddMethod(@exp_PutValuesB, 'procedure SimbaExt.SetData(var Matrix:TByteMatrix; const indices:TPointArray; const values:TByteArray);');
AddMethod(@exp_PutValuesI, 'procedure SimbaExt.SetData(var Matrix:TIntMatrix; const indices:TPointArray; const values:TIntArray); overload;');
AddMethod(@exp_PutValuesF, 'procedure SimbaExt.SetData(var Matrix:TFloatMatrix; const indices:TPointArray; const values:TFloatArray); overload;');
AddMethod(@exp_PutValuesD, 'procedure SimbaExt.SetData(var Matrix:TDoubleMatrix; const indices:TPointArray; const values:TDoubleArray); overload;');
AddMethod(@exp_PutValuesE, 'procedure SimbaExt.SetData(var Matrix:TExtMatrix; const indices:TPointArray; const values:TExtArray); overload;');

AddMethod(@exp_CombineMatB, 'function SimbaExt.CombineMatrix(const Mat1, Mat2:TByteMatrix; Op:Char): TByteMatrix;');
AddMethod(@exp_CombineMatI, 'function SimbaExt.CombineMatrix(const Mat1, Mat2:TIntMatrix; Op:Char): TIntMatrix; overload;');
AddMethod(@exp_CombineMatF, 'function SimbaExt.CombineMatrix(const Mat1, Mat2:TFloatMatrix; Op:Char): TFloatMatrix; overload;');
AddMethod(@exp_CombineMatD, 'function SimbaExt.CombineMatrix(const Mat1, Mat2:TDoubleMatrix; Op:Char): TDoubleMatrix; overload;');
AddMethod(@exp_CombineMatE, 'function SimbaExt.CombineMatrix(const Mat1, Mat2:TExtMatrix; Op:Char): TExtMatrix; overload;');

AddMethod(@exp_NormalizeMatB, 'function SimbaExt.Normalize(const Mat:TByteMatrix; Alpha:Single=0; Beta:Single=1): TFloatMatrix;');
AddMethod(@exp_NormalizeMatI, 'function SimbaExt.Normalize(const Mat:TIntMatrix; Alpha:Double=0; Beta:Double=1): TDoubleMatrix; overload;');
AddMethod(@exp_NormalizeMatF, 'function SimbaExt.Normalize(const Mat:TFloatMatrix; Alpha:Single=0; Beta:Single=1): TFloatMatrix; overload;');
AddMethod(@exp_NormalizeMatD, 'function SimbaExt.Normalize(const Mat:TDoubleMatrix; Alpha:Double=0; Beta:Double=1): TDoubleMatrix; overload;');
AddMethod(@exp_NormalizeMatE, 'function SimbaExt.Normalize(const Mat:TExtMatrix; Alpha:Extended=0; Beta:Extended=1): TExtMatrix; overload;');

AddMethod(@exp_GetAreaB, 'function SimbaExt.GetArea(const Mat:TByteMatrix; X1,Y1,X2,Y2:Integer): TByteMatrix;');
AddMethod(@exp_GetAreaI, 'function SimbaExt.GetArea(const Mat:TIntMatrix; X1,Y1,X2,Y2:Integer): TIntMatrix; overload;');
AddMethod(@exp_GetAreaF, 'function SimbaExt.GetArea(const Mat:TFloatMatrix; X1,Y1,X2,Y2:Integer): TFloatMatrix; overload;');
AddMethod(@exp_GetAreaD, 'function SimbaExt.GetArea(const Mat:TDoubleMatrix; X1,Y1,X2,Y2:Integer): TDoubleMatrix; overload;');
AddMethod(@exp_GetAreaE, 'function SimbaExt.GetArea(const Mat:TExtMatrix; X1,Y1,X2,Y2:Integer): TExtMatrix; overload;');

AddMethod(@exp_GetColsB, 'function SimbaExt.GetCols(const Mat:TByteMatrix; FromCol, ToCol:Int32): TByteMatrix;');
AddMethod(@exp_GetColsI, 'function SimbaExt.GetCols(const Mat:TIntMatrix; FromCol, ToCol:Int32): TIntMatrix; overload;');
AddMethod(@exp_GetColsF, 'function SimbaExt.GetCols(const Mat:TFloatMatrix; FromCol, ToCol:Int32): TFloatMatrix; overload;');
AddMethod(@exp_GetColsD, 'function SimbaExt.GetCols(const Mat:TDoubleMatrix; FromCol, ToCol:Int32): TDoubleMatrix; overload;');
AddMethod(@exp_GetColsE, 'function SimbaExt.GetCols(const Mat:TExtMatrix; FromCol, ToCol:Int32): TExtMatrix; overload;');

AddMethod(@exp_GetRowsB, 'function SimbaExt.GetRows(const Mat:TByteMatrix; FromRow, ToRow:Int32): TByteMatrix;');
AddMethod(@exp_GetRowsI, 'function SimbaExt.GetRows(const Mat:TIntMatrix; FromRow, ToRow:Int32): TIntMatrix; overload;');
AddMethod(@exp_GetRowsF, 'function SimbaExt.GetRows(const Mat:TFloatMatrix; FromRow, ToRow:Int32): TFloatMatrix; overload;');
AddMethod(@exp_GetRowsD, 'function SimbaExt.GetRows(const Mat:TDoubleMatrix; FromRow, ToRow:Int32): TDoubleMatrix; overload;');
AddMethod(@exp_GetRowsE, 'function SimbaExt.GetRows(const Mat:TExtMatrix; FromRow, ToRow:Int32): TExtMatrix; overload;');

AddMethod(@exp_FlipMatB, 'function SimbaExt.Flip(const Mat:TByteMatrix): TByteMatrix;');
AddMethod(@exp_FlipMatI, 'function SimbaExt.Flip(const Mat:TIntMatrix): TIntMatrix; overload;');
AddMethod(@exp_FlipMatF, 'function SimbaExt.Flip(const Mat:TFloatMatrix): TFloatMatrix; overload;');
AddMethod(@exp_FlipMatD, 'function SimbaExt.Flip(const Mat:TDoubleMatrix): TDoubleMatrix; overload;');
AddMethod(@exp_FlipMatE, 'function SimbaExt.Flip(const Mat:TExtMatrix): TExtMatrix; overload;');

AddMethod(@exp_CumSumB, 'function SimbaExt.CumSum(const Mat:TByteMatrix; axis:Int8): TIntMatrix;');
AddMethod(@exp_CumSumI, 'function SimbaExt.CumSum(const Mat:TIntMatrix; axis:Int8): TIntMatrix; overload;');
AddMethod(@exp_CumSumF, 'function SimbaExt.CumSum(const Mat:TFloatMatrix; axis:Int8): TFloatMatrix; overload;');
AddMethod(@exp_CumSumD, 'function SimbaExt.CumSum(const Mat:TDoubleMatrix; axis:Int8): TDoubleMatrix; overload;');
AddMethod(@exp_CumSumE, 'function SimbaExt.CumSum(const Mat:TExtMatrix; axis:Int8): TExtMatrix; overload;');

AddMethod(@exp_PadMatB, 'function SimbaExt.Pad(const Mat:TByteMatrix; pre, post:TSize2D): TByteMatrix;');
AddMethod(@exp_PadMatI, 'function SimbaExt.Pad(const Mat:TIntMatrix; pre, post:TSize2D): TIntMatrix; overload;');
AddMethod(@exp_PadMatF, 'function SimbaExt.Pad(const Mat:TFloatMatrix; pre, post:TSize2D): TFloatMatrix; overload;');
AddMethod(@exp_PadMatD, 'function SimbaExt.Pad(const Mat:TDoubleMatrix; pre, post:TSize2D): TDoubleMatrix; overload;');
AddMethod(@exp_PadMatE, 'function SimbaExt.Pad(const Mat:TExtMatrix; pre, post:TSize2D): TExtMatrix; overload;');