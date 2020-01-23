@n = common global i32 0, align 4
@x = common global i32 0, align 4
@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@.str.1 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
define void @prime()
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = load i32, i32* @x, align 4
  %4 = sdiv i32 %3, 2
  store i32 %4, i32* %2, align 4
  br label %5
  
5:
  %6 = load i32, i32* @x, align 4
  %7 = load i32, i32* @x, align 4
  %8 = load i32, i32* %2, align 4
  %9 = sdiv i32 %7, %8
  %10 = load i32, i32* %2, align 4
  %11 = mul nsw i32 %9, %10
  %12 = icmp ne i32 %6, %11
  br i1 %12, label %13, label %16
  
13:
  %14 = load i32, i32* %2, align 4
  %15 = sub nsw i32 %14, 1
  store i32 %15, i32* %2, align 4
  br label %5
  
16:
  %17 = load i32, i32* %2, align 4
  %18 = icmp eq i32 %17, 1
  br i1 %18, label %19, label %22
  
19:
  %20 = load i32, i32* @x, align 4
  %21 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 %20)
  br label %22
  
22:
  ret void
}

define i32 @main() {
  %1 = alloca i32, align 4
  %2 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.1, i64 0, i64 0), i32* @n)
  br label %3
  
3:
  %4 = load i32, i32* @n, align 4
  %5 = icmp slt i32 1, %4
  br i1 %5, label %6, label %11
  
6:
  %7 = load i32, i32* @n, align 4
  store i32 %7, i32* @x, align 4
  call void @prime()
  br label %8
  
8:
  %9 = load i32, i32* @n, align 4
  %10 = sub nsw i32 %9, 1
  store i32 %10, i32* @n, align 4
  br label %3
  
11:
  ret i32 0
}
declare dso_local i32 @printf(i8*, ...) #1
declare dso_local i32 @__isoc99_scanf(i8*, ...) #1
