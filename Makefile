
.PHONY: all day1

all: run-day1 run-day2 run-day3 run-day4 run-day5 run-day6 run-day7

run-day%: day%
	$(MAKE) -C $<
