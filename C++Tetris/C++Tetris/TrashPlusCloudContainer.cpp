#include "TrashPlusCloudContainer.h"
#include <iostream>
void TrashPlusCloudContainer::init()
{
	int count = 0;
	int k = 0;
	for (int i = 20; i > 0; i--)
	{
		for (int j = 0; j < 14; j++)
		{
			if ((j == 0) || (j == 13))
			{
				m_total_block[i][j] = 1;
			}
			else {
				m_total_block[i][j] = 0;
			}
			
			if (i < 19 && i > 6 && (j % 2 == 0) && (i%3==0)) {
				
		
				m_total_block[i][j] = 1;
				
				
			}

		}
		
		
	}
	//화면의 제일 밑의 줄은 1로 채운다.
	for (int j = 0; j < 14; j++)
		m_total_block[20][j] = 1;


	/*m_level = 0;
	m_lines = 0;*/
	m_ab_x = 5;
	m_ab_y = 1;
}
