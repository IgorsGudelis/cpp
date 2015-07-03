#ifndef DZ20_1_H
#define DZ20_1_H

class Counter
{
private:
	int number;
public:
	Counter(int =0);
	void SetMin();
	void SetMax();
	void PlusOne();
	int CurrentValue();
};
#endif