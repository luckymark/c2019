#include"basic.h"
#include"calculate.h"
int calculate(int* board1)//π¿÷µÀ„∑®
{
	int pointstring = 0;
	int tempscore = 0;
	int i;
	for (i = 0; i < 10; i++)
	{
		 if (board1[i] == 2 && board1[i + 1] == 2 && board1[i + 2] == 2 && board1[i + 3] == 2 && board1[i + 4] == 2)
		{
			pointstring = 1;
			tempscore += FIVE;

		}


		 else if (board1[i] == 0 && board1[i + 1] == 2 && board1[i + 2] == 2 && board1[i + 3] == 2 && board1[i + 4] == 2 && board1[i + 5] == 0)
		{
			pointstring = 2;
			tempscore += FOUR;

		}


		 else if (board1[i] == 0 && board1[i + 1] == 2 && board1[i + 2] == 2 && board1[i + 3] == 2 && board1[i + 4] == 2 && board1[i + 5] == 4)
		{
			pointstring = 7;
			tempscore += BLOCKED_FOUR;

		}


		else if (board1[i] == 2 && board1[i + 1] == 2 && board1[i + 2] == 0 && board1[i + 3] == 2 && board1[i + 4] == 2)
		{
			pointstring = 9;
			tempscore += BLOCKED_FOUR;

		}


		else if (board1[i] == 4 && board1[i + 1] == 2 && board1[i + 2] == 2 && board1[i + 3] == 2 && board1[i + 4] == 2 && board1[i + 5] == 0)
		{
			pointstring = 8;
			tempscore += BLOCKED_FOUR;

		}


		else if (board1[i] == 2 && board1[i + 1] == 0 && board1[i + 2] == 2 && board1[i + 3] == 2 && board1[i + 4] == 2)
		{
			pointstring = 10;
			tempscore += BLOCKED_FOUR;

		}


		else if (board1[i] == 2 && board1[i + 1] == 2 && board1[i + 2] == 2 && board1[i + 3] == 0 && board1[i + 4] == 2)
		{
			pointstring = 11;
			tempscore += BLOCKED_FOUR;

		}


		else if (board1[i] == 0 && board1[i + 1] == 2 && board1[i + 2] == 2 && board1[i + 3] == 2 && board1[i + 4] == 0 )
		{

			pointstring = 3;
			tempscore += THREE;

		}




		else if (board1[i] == 0 && board1[i + 1] == 2 && board1[i + 2] == 2 && board1[i + 3] == 0 && board1[i + 4] == 2 && board1[i + 5] == 0)
		{
			pointstring = 5;
			tempscore += THREE;

		}


		else if (board1[i] == 0 && board1[i + 1] == 2 && board1[i + 2] == 0 && board1[i + 3] == 2 && board1[i + 4] == 2 && board1[i + 5] == 0)
		{
			pointstring = 6;
			tempscore += THREE;

		}


		else if (board1[i] == 0 && board1[i + 1] == 0 && board1[i + 2] == 2 && board1[i + 3] == 2 && board1[i + 4] == 2 && board1[i + 5] == 4)
		{
			pointstring = 6;
			tempscore += BLOCKED_THREE;

		}
		// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };

		else if (board1[i] == 0 && board1[i + 1] == 2 && board1[i + 2] == 0 && board1[i + 3] == 2 && board1[i + 4] == 2 && board1[i + 5] == 4)
		{
			pointstring = 6;
			tempscore += BLOCKED_THREE;

		}
		else if (board1[i] == 0 && board1[i + 1] == 2 && board1[i + 2] == 2 && board1[i + 3] == 2 && board1[i + 4] == 0 && board1[i + 5] == 4)
	    {
			 pointstring = 6;
			 tempscore += BLOCKED_THREE;

	    }// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };

		else if (board1[i] == 0 && board1[i + 1] == 2 && board1[i + 2] == 2 && board1[i + 3] == 0 && board1[i + 4] == 2 && board1[i + 5] == 4)
		{
			pointstring = 6;
			tempscore += BLOCKED_THREE;
		}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };


		else if (board1[i] == 4 && board1[i + 1] == 2 && board1[i + 2] == 2 && board1[i + 3] == 2 && board1[i + 4] == 0 && board1[i + 5] == 0)
		{
			pointstring = 6;
			tempscore += BLOCKED_THREE;

		}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };


		else if (board1[i] == 4 && board1[i + 1] == 2 && board1[i + 2] == 2 && board1[i + 3] == 0 && board1[i + 4] == 2 && board1[i + 5] == 0)
		{
			pointstring = 6;
			tempscore += BLOCKED_THREE;

		}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };

		else if (board1[i] == 4 && board1[i + 1] == 2 && board1[i + 2] == 0 && board1[i + 3] == 2 && board1[i + 4] == 2 && board1[i + 5] == 0)
		{
			pointstring = 6;
			tempscore += BLOCKED_THREE;

		}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };


		else if (board1[i] == 4 && board1[i + 1] == 0 && board1[i + 2] == 2 && board1[i + 3] == 2 && board1[i + 4] == 2 && board1[i + 5] == 0)
		{
			pointstring = 6;
			tempscore += BLOCKED_THREE;
		}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };


		else if (board1[i] == 0 && board1[i + 1] == 0 && board1[i + 2] == 2 && board1[i + 3] == 2 && board1[i + 4] == 2)
		{
			pointstring = 6;
			tempscore += BLOCKED_THREE;

		}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };


		else if (board1[i] == 2 && board1[i + 1] == 0 && board1[i + 2] == 0 && board1[i + 3] == 2 && board1[i + 4] == 2)
		{
			pointstring = 6;
			tempscore += BLOCKED_THREE;

		}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };


		else if (board1[i] == 2 && board1[i + 1] == 0 && board1[i + 2] == 2 && board1[i + 3] == 0 && board1[i + 4] == 2)
		{
			pointstring = 6;
			tempscore += BLOCKED_THREE;

		}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };
		else if (board1[i] == 2 && board1[i + 1] == 0 && board1[i + 2] == 2 && board1[i + 3] == 2 && board1[i + 4] == 0)
		{
		pointstring = 6;
		tempscore += BLOCKED_THREE;

		}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };
		else if (board1[i] == 0 && board1[i + 1] == 2 && board1[i + 2] == 0 && board1[i + 3] == 2 && board1[i + 4] == 2)
		{
		pointstring = 6;
		tempscore += BLOCKED_THREE;

		}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };
		else if (board1[i] == 2 && board1[i + 1] == 0 && board1[i + 2] == 0 && board1[i + 3] == 2 && board1[i + 4] == 2)
		{
		pointstring = 6;
		tempscore += BLOCKED_THREE;

		}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };
		else if (board1[i] == 2 && board1[i + 1] == 2 && board1[i + 2] == 0 && board1[i + 3] == 2 && board1[i + 4] == 2)
		{
		pointstring = 6;
		tempscore += BLOCKED_THREE;

		}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };
		
		else if (board1[i] == 2 && board1[i + 1] == 2 && board1[i + 2] == 0 && board1[i + 3] == 0 && board1[i + 4] == 2)
		{
		pointstring = 6;
		tempscore += BLOCKED_THREE;

		}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };
		else if (board1[i] == 0 && board1[i + 1] == 2 && board1[i + 2] == 2 && board1[i + 3] == 0 && board1[i + 4] == 2)
		{
		pointstring = 6;
		tempscore += BLOCKED_THREE;

		}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };

		else if (board1[i] == 2 && board1[i + 1] == 2 && board1[i + 2] == 2 && board1[i + 3] == 0 && board1[i + 4] == 0)
		{
		    pointstring = 6;
		    tempscore += BLOCKED_THREE;
		}
		else if (board1[i] == 0 && board1[i + 1] == 0 && board1[i + 2] == 2 && board1[i + 3] == 2 && board1[i + 4] == 0 && board1[i + 5] == 0)
		{
			pointstring = 12;
			tempscore += TWO;
		}


		else if (board1[i] == 0 && board1[i + 1] == 0 && board1[i + 2] == 2 && board1[i + 3] == 0 && board1[i + 4] == 2 && board1[i + 5] == 0)
		{
			pointstring = 13;
			tempscore += TWO;

		}

		//{"000110", "001010", "001100", "001100", "010100", "011000", "000110", "010010", "010100", "001010", "010010", "011000", };
		else if (board1[i] == 0 && board1[i + 1] == 2 && board1[i + 2] == 0 && board1[i + 3] == 2 && board1[i + 4] == 0 && board1[i + 5] == 0)
		{
			pointstring = 14;
			tempscore += TWO;

		}

		//{"000112", "001012", "010012", "10001", "2010102", "2011002", "211000", "210100", "210010", "2001102"};
		else if (board1[i] == 0 && board1[i + 1] == 0 && board1[i + 2] == 2 && board1[i + 3] == 0 && board1[i + 4] == 2 && board1[i + 5] == 4)
		{
			pointstring = 13;
			tempscore += BLOCKED_TWO;

		}
		else if (board1[i] == 0 && board1[i + 1] == 0 && board1[i + 2] == 0 && board1[i + 3] == 2 && board1[i + 4] == 2 && board1[i + 5] == 4)
		{
		pointstring = 13;
		tempscore += BLOCKED_TWO;

		}		//{"000112", "001012", "010012", "10001", "2010102", "2011002", "211000", "210100", "210010", "2001102"};



		else if (board1[i] == 0 && board1[i + 1] == 2 && board1[i + 2] == 0 && board1[i + 3] == 0 && board1[i + 4] == 2 && board1[i + 5] == 4)
		{
			pointstring = 13;
			tempscore += BLOCKED_TWO;

		}		//{"000112", "001012", "010012", "10001", "2010102", "2011002", "211000", "210100", "210010", "2001102"};


		else if (board1[i] == 2 && board1[i + 1] == 0 && board1[i + 2] == 0 && board1[i + 3] == 0 && board1[i + 4] == 2 )
		{
			pointstring = 13;
			tempscore += BLOCKED_TWO;

		}		//{"000112", "001012", "010012", "10001", "2010102", "2011002", "211000", "210100", "210010", "2001102"};


		else if (board1[i] == 4 && board1[i + 1] == 0 && board1[i + 2] == 2 && board1[i + 3] == 0 && board1[i + 4] == 2 && board1[i + 5] == 0 && board1[i + 6] == 4)
		{
			pointstring = 13;
			tempscore += BLOCKED_TWO;

		}		//{"000112", "001012", "010012", "10001", "2010102", "2011002", "211000", "210100", "210010", "2001102"};


		else if (board1[i] == 4 && board1[i + 1] == 0 && board1[i + 2] == 2 && board1[i + 3] == 2 && board1[i + 4] == 0 && board1[i + 5] == 0 && board1[i + 6] == 4)
		{
			pointstring = 13;
			tempscore += BLOCKED_TWO;

		}


		else if (board1[i] == 4 && board1[i + 1] == 2 && board1[i + 2] == 2 && board1[i + 3] == 0 && board1[i + 4] == 0 && board1[i + 5] == 0)
		{
			pointstring = 13;
			tempscore += BLOCKED_TWO;

		}

		else if (board1[i] == 4 && board1[i + 1] == 2 && board1[i + 2] == 0 && board1[i + 3] == 2 && board1[i + 4] == 0 && board1[i + 5] == 0)
		{
			pointstring = 13;
			tempscore += BLOCKED_TWO;

		}		//{"000112", "001012", "010012", "10001", "2010102", "2011002", "211000", "210100", "210010", "2001102"};

		else if (board1[i] == 4 && board1[i + 1] == 2 && board1[i + 2] == 0 && board1[i + 3] == 0 && board1[i + 4] == 2 && board1[i + 5] == 0)
		{
			pointstring = 13;
			tempscore += BLOCKED_TWO;
		}


		else if (board1[i] == 4 && board1[i + 1] == 0 && board1[i + 2] == 0 && board1[i + 3] == 2 && board1[i + 4] == 2 && board1[i + 5] == 0 && board1[i + 6] == 4)
		{
			pointstring = 13;
			tempscore += BLOCKED_TWO;

		}


		else if (board1[i] == 0 && board1[i + 1] == 0 && board1[i + 2] == 0 && board1[i + 3] == 2 && board1[i + 4] == 0 && board1[i + 5] == 0)
		{
			pointstring = 15;
			tempscore += ONE;

		}


		else if (board1[i] == 0 && board1[i + 1] == 0 && board1[i + 2] == 2 && board1[i + 3] == 0 && board1[i + 4] == 0 && board1[i + 5] == 0)
		{
			pointstring = 16;
			tempscore += ONE;

		}
	}
		return tempscore;
	}
	int anticalculate(int board1[])
	{

		int pointstring = 0;
		int tempscore = 0;
		int i;
		for (i = 0; i < 10; i++)
		{
			if (board1[i] == 4 && board1[i + 1] == 4 && board1[i + 2] == 4 && board1[i + 3] == 4 && board1[i + 4] == 4)
			{
				pointstring = 1;
				tempscore += -FIVE;

			}


			else if (board1[i] == 0 && board1[i + 1] == 4 && board1[i + 2] == 4 && board1[i + 3] == 4 && board1[i + 4] == 4 && board1[i + 5] == 0)
			{
				pointstring = 2;
				tempscore += -FOUR;

			}


			else if (board1[i] == 4 && board1[i + 1] == 4 && board1[i + 2] == 4 && board1[i + 3] == 4 && board1[i + 4] == 0)
			{
				pointstring = 7;
				tempscore += -BLOCKED_FOUR;

			}

			else if (board1[i] == 0 && board1[i + 1] == 4 && board1[i + 2] == 4 && board1[i + 3] == 4 && board1[i + 4] == 4)
			{
				pointstring = 8;
				tempscore += -BLOCKED_FOUR;

			}

			else if (board1[i] == 4 && board1[i + 1] == 4 && board1[i + 2] == 0 && board1[i + 3] == 4 && board1[i + 4] == 4)
			{
				pointstring = 9;
				tempscore += -BLOCKED_FOUR;

			}
			else if (board1[i] == 4 && board1[i + 1] == 0 && board1[i + 2] == 4 && board1[i + 3] == 4 && board1[i + 4] == 4)
			{
				pointstring += 10;
				tempscore += -BLOCKED_FOUR;

			}
			else if (board1[i] == 4 && board1[i + 1] == 4 && board1[i + 2] == 4 && board1[i + 3] == 0 && board1[i + 4] == 4)
			{
				pointstring = 11;
				tempscore += -BLOCKED_FOUR;

			}


			else if (board1[i] == 0 && board1[i + 1] == 4 && board1[i + 2] == 4 && board1[i + 3] == 4 && board1[i + 4] == 0)
			{

				pointstring = 3;
				tempscore += -THREE;

			}
			else if (board1[i] == 0 && board1[i + 1] == 4 && board1[i + 2] == 4 && board1[i + 3] == 0 && board1[i + 4] == 4 && board1[i + 5] == 0)
			{
				pointstring = 5;
				tempscore += -THREE;

			}
			else if (board1[i] == 0 && board1[i + 1] == 4 && board1[i + 2] == 0 && board1[i + 3] == 4 && board1[i + 4] == 4 && board1[i + 5] == 0)
			{
				pointstring = 6;
				tempscore += -THREE;

			}

			else if (board1[i] == 0 && board1[i + 1] == 0 && board1[i + 2] == 4 && board1[i + 3] == 4 && board1[i + 4] == 4 && board1[i + 5] == 2)
			{
				pointstring = 6;
				tempscore += -BLOCKED_THREE;

			}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };

			else if (board1[i] == 0 && board1[i + 1] == 4 && board1[i + 2] == 0 && board1[i + 3] == 4 && board1[i + 4] == 4 && board1[i + 5] == 2)
			{
				pointstring = 6;
				tempscore += -BLOCKED_THREE;

			}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };
			else if (board1[i] == 0 && board1[i + 1] == 4 && board1[i + 2] == 4 && board1[i + 3] == 0 && board1[i + 4] == 4 && board1[i + 5] == 2)
			{
				pointstring = 6;
				tempscore += -BLOCKED_THREE;

			}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };
			else if (board1[i] == 0 && board1[i + 1] == 4 && board1[i + 2] == 4 && board1[i + 3] ==4 && board1[i + 4] == 0 && board1[i + 5] == 2)
			{
				pointstring = 6;
				tempscore += -BLOCKED_THREE;

			}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };
			else if (board1[i] == 2 && board1[i + 1] == 4 && board1[i + 2] == 4&& board1[i + 3] == 4 && board1[i + 4] == 0 && board1[i + 5] == 0)
			{
				pointstring = 6;
				tempscore += -BLOCKED_THREE;
				// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };
			}
			else if (board1[i] == 2 && board1[i + 1] == 4 && board1[i + 2] == 4 && board1[i + 3] == 0 && board1[i + 4] == 4 && board1[i + 5] == 0)
			{
			pointstring = 6;
			tempscore += -BLOCKED_THREE;
			// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };
			}
			else if (board1[i] == 2 && board1[i + 1] == 4 && board1[i + 2] ==0 && board1[i + 3] == 4 && board1[i + 4] == 4 && board1[i + 5] == 0)
			{
			pointstring = 6;
			tempscore += -BLOCKED_THREE;
			// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };
			}
			else if (board1[i] == 2 && board1[i + 1] == 0 && board1[i + 2] == 4 && board1[i + 3] == 4 && board1[i + 4] == 4 && board1[i + 5] == 0)
			{
				pointstring = 6;
				tempscore += -BLOCKED_THREE;
				// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };
			}



			else if (board1[i] == 0 && board1[i + 1] == 0 && board1[i + 2] == 4 && board1[i + 3] == 4 && board1[i + 4] == 4)
			{
				pointstring = 6;
				tempscore += -BLOCKED_THREE;

			}
			else if (board1[i] == 4 && board1[i + 1] == 0 && board1[i + 2] == 0 && board1[i + 3] == 4 && board1[i + 4] == 4)
			{
				pointstring = 6;
				tempscore += -BLOCKED_THREE;

			}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };
			else if (board1[i] == 4 && board1[i + 1] == 4 && board1[i + 2] == 0 && board1[i + 3] == 0 && board1[i + 4] == 4)
			{
			pointstring = 6;
			tempscore += -BLOCKED_THREE;

			}
			else if (board1[i] == 4 && board1[i + 1] == 0 && board1[i + 2] == 4 && board1[i + 3] == 0 && board1[i + 4] == 4)
			{
			pointstring = 6;
			tempscore += -BLOCKED_THREE;

			}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };
			else if (board1[i] == 4 && board1[i + 1] == 0 && board1[i + 2] == 4 && board1[i + 3] == 4 && board1[i + 4] == 0)
			{
			pointstring = 6;
			tempscore += -BLOCKED_THREE;

			}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };

			else if (board1[i] == 0 && board1[i + 1] == 4 && board1[i + 2] == 0 && board1[i + 3] == 4 && board1[i + 4] == 4)
			{
				pointstring = 6;
				tempscore += -BLOCKED_THREE;
			}
			else if (board1[i] == 4 && board1[i + 1] == 0 && board1[i + 2] == 0 && board1[i + 3] == 4 && board1[i + 4] == 4)
			{
			pointstring = 6;
			tempscore += -BLOCKED_THREE;

			}// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };


			else if (board1[i] == 4 && board1[i + 1] == 4 && board1[i + 2] == 0 && board1[i + 3] == 4 && board1[i + 4] == 0)
			{
				pointstring = 6;
				tempscore += -BLOCKED_THREE;
				// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };
			}
			else if (board1[i] == 0 && board1[i + 1] == 4 && board1[i + 2] == 4 && board1[i + 3] == 0 && board1[i + 4] == 4)
			{
			pointstring = 6;
			tempscore += -BLOCKED_THREE;

			}
			// {"002221", "020221", "022021", "022201", "122200", "122020", "120220", "102220", "00222", "20022", "20202", "20220", "02022", "20022", "22002", "22020", "02202", "20202", "22002", "22200", };
			

			else if (board1[i] == 4 && board1[i + 1] == 4 && board1[i + 2] == 0 && board1[i + 3] == 0 && board1[i + 4] == 4)
			{
			pointstring = 6;
			tempscore += -BLOCKED_THREE;

			}
			else if (board1[i] == 4 && board1[i + 1] == 4 && board1[i + 2] == 4 && board1[i + 3] == 0 && board1[i + 4] == 0)
			{
				pointstring = 6;
				tempscore += -BLOCKED_THREE;

			}

			else if (board1[i] == 0 && board1[i + 1] == 0 && board1[i + 2] == 4 && board1[i + 3] == 4 && board1[i + 4] == 0 && board1[i + 5] == 0)
			{
				pointstring = 12;
				tempscore += -TWO;

			}
			else if (board1[i] == 0 && board1[i + 1] == 0 && board1[i + 2] == 4 && board1[i + 3] == 0 && board1[i + 4] == 4 && board1[i + 5] == 0)
			{
				pointstring = 13;
				tempscore += -TWO;

			}
			else if (board1[i] == 0 && board1[i + 1] == 4 && board1[i + 2] == 0 && board1[i + 3] == 4 && board1[i + 4] == 0 && board1[i + 5] == 0)
			{
				pointstring = 14;
				tempscore += -TWO;

			}
			else if (board1[i] == 0 && board1[i + 1] == 0 && board1[i + 2] == 4 && board1[i + 3] == 0 && board1[i + 4] == 4 && board1[i + 5] == 2)
			{
			pointstring = 13;
			tempscore += -BLOCKED_TWO;

			}		//{"000112", "001012", "010012", "10001", "2010102", "2011002", "211000", "210100", "210010", "2001102"};


			else if (board1[i] == 0 && board1[i + 1] == 0 && board1[i + 2] == 0 && board1[i + 3] == 4 && board1[i + 4] == 4 && board1[i + 5] == 2)
			{
			pointstring = 13;
			tempscore += -BLOCKED_TWO;

			}
			else if (board1[i] == 0 && board1[i + 1] == 4 && board1[i + 2] == 0 && board1[i + 3] == 0 && board1[i + 4] == 4 && board1[i + 5] == 2)
			{
			pointstring = 13;
			tempscore += -BLOCKED_TWO;

			}
			else if (board1[i] == 4 && board1[i + 1] == 0 && board1[i + 2] == 0 && board1[i + 3] == 0 && board1[i + 4] == 4)
			{
			pointstring = 13;
			tempscore += -BLOCKED_TWO;
			//{"000112", "001012", "010012", "10001", "2010102", "2011002", "211000", "210100", "210010", "2001102"};
			}
			else if (board1[i] == 2 && board1[i + 1] == 0 && board1[i + 2] == 4 && board1[i + 3] == 0 && board1[i + 4] == 4 && board1[i + 5] == 0 && board1[i + 6] == 2)
			{
			pointstring = 13;
			tempscore += -BLOCKED_TWO;

			}
			else if (board1[i] == 2 && board1[i + 1] == 0 && board1[i + 2] == 4 && board1[i + 3] == 4 && board1[i + 4] == 0 && board1[i + 5] == 0 && board1[i + 6] == 2)
			{
			pointstring = 13;
			tempscore += -BLOCKED_TWO;

			}
			else if (board1[i] == 2 && board1[i + 1] == 4 && board1[i + 2] == 4 && board1[i + 3] == 0 && board1[i + 4] == 0 && board1[i + 5] == 0)
			{
			pointstring = 13;
			tempscore += -BLOCKED_TWO;

			}
			else if (board1[i] == 2 && board1[i + 1] == 4 && board1[i + 2] == 0 && board1[i + 3] == 4 && board1[i + 4] == 0 && board1[i + 5] == 0)
			{
			pointstring = 13;
			tempscore += -BLOCKED_TWO;

			}
			else if (board1[i] == 2 && board1[i + 1] == 4 && board1[i + 2] == 0 && board1[i + 3] == 0 && board1[i + 4] == 4 && board1[i + 5] == 0)
			{
			pointstring = 13;
			tempscore += -BLOCKED_TWO;

			}
			else if (board1[i] == 2 && board1[i + 1] == 0 && board1[i + 2] == 0 && board1[i + 3] == 4 && board1[i + 4] == 4 && board1[i + 5] == 0 && board1[i + 6] == 2)
			{
			pointstring = 13;
			tempscore += -BLOCKED_TWO;

			}
			else if (board1[i] == 0 && board1[i + 1] == 0 && board1[i + 2] == 0 && board1[i + 3] == 4 && board1[i + 4] == 0 && board1[i + 5] == 0)
			{
				pointstring = 15;
				tempscore += -ONE;

			}
			else if (board1[i] == 0 && board1[i + 1] == 0 && board1[i + 2] == 4 && board1[i + 3] == 0 && board1[i + 4] == 0 && board1[i + 5] == 0)
			{
				pointstring = 16;
				tempscore += -ONE;

			}
		}
		return tempscore;
	
}