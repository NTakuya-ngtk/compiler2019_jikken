program TEST;
var x,y,z,k;
procedure sum(x,y,z);
begin
   k := x + y + z;
end;
begin
   x := 3 + 4;
   y := x - 5;
   z := 10 * 10;
   sum(x,y,z)
end.
