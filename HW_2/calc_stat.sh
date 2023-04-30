#!/bin/bash

#checks if we recived one argument and if the file xxxxxx_stat exists
if [[ $# -ne 1 ]]; then
    echo "Wrong number of arguments" >&2
    exit 1
elif [[ ! -e "${1}" ]]; then
    echo "Course not found" >&2
    exit 1
elif [[ -e "${1:0:6}_stat" ]]; then
    rm -r "${1:0:6}_stat"
fi

# create the xxxxxx_stat directory
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
fp="$SCRIPT_DIR/$1"
dirname="${1:0:6}_stat"
mkdir "$dirname"
cd "$dirname"

# creating histogram for 10 bins
data=$(cat "$fp")
((bins=10))
echo "$data" | awk -v bins=$bins '{if($1 ==100){count[9]++;}  bin=int($1/bins); count[bin]++} END {for (i=0; i<bins; i++) print i*bins, (i+1)*bins, count[i]}' | sort -n | awk '{print $1 " - " $2 " : " $3}' >> histograma.txt

# running the C programs to get the data to put in statistics
gcc -g -Wall "$SCRIPT_DIR/min.c" -o min.exe
gcc -g -Wall "$SCRIPT_DIR/max.c" -o max.exe
gcc -g -Wall "$SCRIPT_DIR/mean.c" -o mean.exe
gcc -g -Wall "$SCRIPT_DIR/median.c" -o median.exe
gcc -g -Wall "$SCRIPT_DIR/hist.c" -o hist.exe

if [[ ! -f "min.exe" || ! -f "max.exe" || ! -f "mean.exe" || ! -f "median.exe" || ! -f "hist.exe" ]]; then
    echo "Error: C program compilation failed" >&2
    exit 1
fi

min=$(./min.exe "$fp") 
max=$(./max.exe "$fp") 
mean=$(./mean.exe "$fp") 
median=$(./median.exe "$fp") 
hist=$(./hist.exe "$fp")|| exit 1
echo "$mean        $median        $min    $max" >> statistics.txt


# calculating the success percentage
((sum=0))
((count=0))
input="$hist"
while read line; do
     
    ((sum=sum+$(echo "$line"| awk '{ print $2}')))
   
    if [[ $(echo "$line" | awk '{print $1}' | awk -F '-' '{print $1}') -gt 54 ]]; then
        ((count=count+$(echo "$line"| awk '{ print $2}')))
    fi
    
done <<< "$hist"
if [[ "$sum" -eq 0 ]]; then
	echo "0" >> statistics.txt
else
	((x=count*100/sum));
    echo "${x}%" >> statistics.txt
  fi
