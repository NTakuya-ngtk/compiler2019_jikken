@x = common global i32 0, align 4
@y = common global i32 0, align 4
@z = common global i32 0, align 4
@k = common global i32 0, align 4

define void @sum(i32, i32, i32)
  %2 = alloca i32, align 4
  %4 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = load i32, i32* %1, align 4
  %8 = load i32, i32* %3, align 4
  %9 = add nsw i32 %7, %8
  %10 = load i32, i32* %5, align 4
  %11 = add nsw i32 %9, %10
  store i32 %11, i32* @k, align 4
  ret void 
}

define i32 @main()
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = add nsw i32 3, 4
  store i32 %2, i32* @x, align 4
  %3 = load i32, i32* @x, align 4
  %4 = sub nsw i32 %3, 5
  store i32 %4, i32* @y, align 4
  %5 = mul nsw i32 10, 10
  store i32 %5, i32* @z, align 4
  %6 = load i32, i32* @x, align 4
  %7 = load i32, i32* @y, align 4
  %8 = load i32, i32* @z, align 4
  call void @sum(i32 %6,)
  ret i32 0
}
