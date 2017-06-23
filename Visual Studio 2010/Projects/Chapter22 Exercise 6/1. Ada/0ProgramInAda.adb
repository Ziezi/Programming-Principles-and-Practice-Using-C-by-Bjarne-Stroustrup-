--A procedure to sort an array of integers into ascending order using Shuffle Sorting
 
type Array_type is array (Positive range <>) of Integer;
 
procedure Shuffle_Sort (X: in out Array_type) is
	Position: Positive;
	Value	: Integer;
begin
	for I in X'First+1 .. X'Last loop
		if X(I) < X(I-1) then
			--Misplaced item found: copy it
			Value := X(I);
			--Scan backwards until correct position found
			for J in reverse X'First .. I-1 loop
				exit when X(J) < Value;
				Position := J;
			end loop;
			--Move intervening value along
			X(Position+1 .. I) := X(Position .. I-1);
			--Put saved copy of item in correct position
			X(Position) := Value;
		end if;
	end loop;
end Shuffle_Sort;