program scanner_test;

var
  i,j,num  : integer;

function divides(x,y : integer) : boolean;
begin
  divides := y = x*(y div x) 
end;


begin
  num := readint();
  i := readint();
  for j := 1 to num do begin
    if divides(i,j) then 
	num := num + i 
  end
end.
