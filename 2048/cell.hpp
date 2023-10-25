class Cell
{
public:
	Cell();
	~Cell();
	bool isMerge() { return merge; };
	void merged() { merge = true; };
	void resetMerge() { merge = false; };
	void setValue(int newValue) { value = newValue; };

private:
	int value = 0;
	bool merge = false;
};