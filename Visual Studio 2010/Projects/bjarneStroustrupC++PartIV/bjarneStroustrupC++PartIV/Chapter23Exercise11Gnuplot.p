#TITTLE 	Plot data		Chapter23Exericse11Gnuplot.p 
#COMMENT
#	Objective: Gnuplot script file for plotting data
#			   from file Chapter23Exerice11.txt to 
#			   analyse growing trend of students.
#		Input: Run: gnuplot> load 'Chapter23Exericse5map.p'
#	   Output: Grade vs Students 
#	   Author: Chris B. Kirov
# 		 Date: 29.04.2017

set title "Students per grade"
set xlabel 'Grade[N]'
set ylabel 'Students[N]'
plot "Chapter23Exercise11.txt" using 1:2
