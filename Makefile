
.PHONY: all day1

all: run-day1 run-day2 run-day3 run-day4

run-day%: day%
	$(MAKE) -C $<
