CC = gcc
CFLAGS = -Wall -g
INCLUDE_DIR = ../include

SRC_DIR = .


SRCS_FREQUENCY_ANALYSIS = $(SRC_DIR)/frequency_analysis.c $(SRC_DIR)/functions.c 

OBJS_FREQUENCY_ANALYSIS = $(SRCS_FREQUENCY_ANALYSIS:.c=.o)

EXEC_FREQUENCY_ANALYSIS = frequency_analysis

all: $(EXEC_FREQUENCY_ANALYSIS)

$(EXEC_FREQUENCY_ANALYSIS): $(OBJS_FREQUENCY_ANALYSIS)
	$(CC) $(CFLAGS) $^ -o $@ 

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE_DIR)/functions.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o $(EXEC_FREQUENCY_ANALYSIS)
