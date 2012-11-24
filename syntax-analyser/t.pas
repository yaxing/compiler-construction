{ 
	This program is lexical and parsing error-free
        and contains undeclared variable  
}

program errorundeclared;
type
	s = string;
	in = integer;
var
	z : in;
	m : in;

function foo(n : in) : in; 
begin
   n := n + 1  {error: b has not been declared }
   foo := n 	
end;

begin
	m := 5;
	z := 7;
	z := m + z;  {error: n has not been declared}
end.