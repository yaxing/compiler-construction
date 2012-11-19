program parser_test;

var
  i,j,num  : integer;

function divides(x,y : integer) : boolean;
begin
  divides := y = x*(y div x) 
end;

function mul(x,y : integer) : boolean;
begin
  divides := y = x*(y div x) 
end;

procedure DrawLine(X : integer; Y : integer);
var Counter, t : integer;
begin
 GotoXy(X,Y); {here I use the parameters}
 textcolor(green);
 for Counter := 1 to 10 do
  begin
   write(chr(196));
  end;
end;

begin
  writestring("How many ?");
  num := readint();
  writestring("Divisor ?");
  i := readint();
  writeint(i);
  for j := 1 to num do begin
    writestring("###########");
    writeint(j);
    if divides(i,j) then 
      writestring("yes")
    else 
      writestring("no");
    writeint(j mod i)  
  end
end.
