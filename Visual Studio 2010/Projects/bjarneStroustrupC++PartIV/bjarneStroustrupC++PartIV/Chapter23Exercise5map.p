#TITTLE 	Plot data		Chapter23Exericse5map.p 
#COMMENT
#	Objective: Gnuplot script file for plotting data
#			   from file Chapter23Exerice5(.*).txt
#		Input: Run: gnuplot> load 'Chapter23Exericse5map.p'
#	   Output: Time complexity graph of map: insert().
#	   Author: Chris B. Kirov
# 		 Date: 27.04.2017

set title "Time Complexity of STL map's operation insert()."
set xlabel 'Sample[N]'
set ylabel 'Time[msec]'
set logscale
plot "Chapter23Exercise5map.txt" using 1:2

