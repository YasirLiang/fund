CC=gcc

htf:htf.c
	$(CC) -o $@ $< -lm

clean:
	rm -rf htf ./*.o 
