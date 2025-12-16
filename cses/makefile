CXX := clang++
CXXFLAGS := -std=c++17 -Wall -Wextra
DEST := bin

% : %.cpp | $(DEST)
	$(CXX) $(CXXFLAGS) $< -o $(DEST)/$@
	./$(DEST)/$@

$(DEST):
	mkdir -p $(DEST)

clean:
	rm -f $(DEST)/*