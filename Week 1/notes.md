man = Manual

mkdir = Make new directory
touch = Make file

grep "..." = Search for "..." 
grep "..." *.txt = Search for "..." in all txt files
grep "..." *.txt > new.txt = Search for "..." in all txt files and put it in a new file called new.txt

grep "..." *.txt | cut -d "," -f # = Search for '' then cut (select) field # from it
grep "..." *.txt | cut -d "," -f # | sort = Search and cut, then sort it
grep "..." *.txt | cut -d "," -f # | sort > new.txt = Search, cut, and sort, then put them into a new file called new.txt
