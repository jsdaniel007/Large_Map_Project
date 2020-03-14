set terminal postscript color
set output "getfunc.ps"
set title "Get Function Performance"
set ylabel "time"
set xlabel "Input Count"
plot [:][:] "timings.data" using 1:2 with line
