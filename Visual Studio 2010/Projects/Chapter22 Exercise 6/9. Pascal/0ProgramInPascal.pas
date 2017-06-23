Program linear_diophantine_equation; {04.04.2017}

var x, y: Integer;

begin
  writeln('All integer solutions of 3x - 7y = 1');
  writeln('For the interval: -50 <= x <= 50 and -25 <= y <= 25:');
  
  for x := -50 to 50 do
    for y := -25 to 25 do
        if 3 * x - 7 * y = 1 then
            writeln('(x, y) = (', x, ' ,', y, ')');
            
   writeln('Press <Enter> to exit...');
   readln;
end.