SOURCE = "src/vitruvianJudge.cpp"
EXEC = "bin/vitruvian"

compile:
	g++ $(SOURCE) -o $(EXEC)

clean:
	rm $(EXEC)