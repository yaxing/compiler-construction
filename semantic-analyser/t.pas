program parser_test;

function divides(x,y : integer) : boolean;
begin
  divides := y = x*(y div x) 
end;

function mul(x,y : integer) : boolean;
begin
  divides := y = x*(y div x) 
end;

procedure DrawLine(X : integer; Y : integer);
var Counter : integer;
begin
 GotoXy(X,Y); {here I use the parameters}
 textcolor(green);
 for Counter := 1 to 10 do
  begin
   write(chr(196));
  end;
end;

begin

end.
