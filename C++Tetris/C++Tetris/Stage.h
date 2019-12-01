#pragma once
class Stage
{
private:
	int m_speed;
	int m_stick_rate;
	int m_clear_line;
public:
	Stage();
	~Stage();
	Stage(const int& speed, const int& stick_rate, const int& clear_line);
	void set_speed(const int& speed);
	void set_stick_rate(const int& stick_rate);
	void set_clear_line(const int& clear_line);
	int get_speed() const;
	int get_stick_rate() const;
	int get_clear_line() const;
};

