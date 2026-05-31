SRCS = $(wildcard src/*.cpp)
OUT  = main

run: $(OUT)
	./$(OUT)

$(OUT): $(SRCS)
	g++ $(SRCS) -o $(OUT) -lsfml-graphics -lsfml-window -lsfml-system -I/opt/homebrew/include -L/opt/homebrew/lib -std=c++17

clean:
	rm -f $(OUT)
