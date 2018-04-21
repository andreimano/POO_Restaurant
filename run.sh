#!/bin/bash
#runs the compiled program with sample data from ./input
obj=./bin/restaurant

if [ ! -e "$obj" ]; then
	printf "I did not find the executable, do you want me to compile it for you? (y/n)\n"
	read decision
	if [ "$decision" == "y" ]; then
		make 1>/dev/null
		printf "..done\nSet 1:\n"
		./bin/restaurant < input1
		printf "\nSet 2:\n"
		./bin/restaurant < input2
	fi
else
	printf "\nSet 1:\n"
	./bin/restaurant < input1
	printf "\nSet 2:\n"
	./bin/restaurant < input2
fi
