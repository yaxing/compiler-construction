program parser_test;

var
  i,j,num  : integer;
 i : boolean;

begin
  writestring("How many ?");
  num := readint();
  writestring("Divisor ?");
  i := readint();
  writeint(i);
  for j := 1 to num do begin
    writestring("###########");
    writeint(j);
    writeint(j mod i)  
  end
end.
