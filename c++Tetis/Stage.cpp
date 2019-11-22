#include "Stage.h"

Stage::Stage()
:Stage(40,40,20)
{
}

Stage::~Stage()
{
}

Stage::Stage(const int& speed, const int& stick_rate, const int& clear_line)
	: m_speed(speed), m_stick_rate(stick_rate), m_clear_line(clear_line)
{
}

void Stage::set_speed(const int& speed)
{
	m_speed = speed;
}

void Stage::set_stick_rate(const int& stick_rate)
{
	m_stick_rate = stick_rate;
}

void Stage::set_clear_line(const int& clear_line)
{
	m_clear_line = clear_line;
}

int Stage::get_speed() const
{
	return m_speed;
}

int Stage::get_stick_rate() const
{
	return m_stick_rate;
}

int Stage::get_clear_line() const
{
	return m_clear_line;
}
