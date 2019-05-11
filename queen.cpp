#include <iostream>
#include <stdlib.h>        
#include <wchar.h>
#include    <io.h>      
#include    <fcntl.h>        
#include <string>
#include <time.h>
using namespace std;
#define SEV 32
#define SPITAK 219
char BLACK = SEV;
char WHITE = SPITAK;
int wb1_tox = -1;
int wb1_syun = -1;
int bb1_tox = -1;
int bb1_syun = -1;
int wharvac[8][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 } };
int bharvac[8][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 } };
int wtaguhi[8][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 } };
int wognakan[8][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 } };
int btaguhi[8][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 } };
int bognakan[8][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 } };
wchar_t *taxtak[8][8] = {
	{ L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020" },
	{ L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020" },
	{ L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020" },
	{ L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020" },
	{ L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020" },
	{ L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020" },
	{ L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020" },
	{ L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020", L"\x0020" }};
void zroyacnel()
{for (int k = 0; k < 8; k++)
	{for (int m = 0; m < 8; m++)
		{wharvac[k][m] = 0;
			bharvac[k][m] = 0;}}}

int figurner[8][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 }};
int virfigures[8][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 } };

void tverovy_simvolnerovi()
{
	for (int i = 0; i < 8; i++)
	{for (int j = 0; j < 8; j++)
		{switch (figurner[i][j])
			{case 10:{taxtak[i][j] = L"\x265A";break;}
				case -10:{taxtak[i][j] = L"\x2654";break;}
				case 9:{taxtak[i][j] = L"\x265B"; break;}
				case -9:{taxtak[i][j] = L"\x2655"; break; }
				case 8:{taxtak[i][j] = L"\x265C"; break; }
				case -8:{taxtak[i][j] = L"\x2656"; break; }
				case 7:{taxtak[i][j] = L"\x265D"; break; }
				case -7:{taxtak[i][j] = L"\x2657"; break; }
				case 6:{taxtak[i][j] = L"\x265E"; break; }
				case -6:{taxtak[i][j] = L"\x2658"; break; }
				case 1:{taxtak[i][j] = L"\x265F"; break; }
				case -1:{taxtak[i][j] = L"\x2659"; break; }
				case 0:{taxtak[i][j] = L"\x0020"; break; }
				//spitak astgh 2605; sev 2606
			}}}}

int wpahanj[16] = {10,9,8,7,7,1,1,1};
int bpahanj[16] = {-10,-7,-6,-1,-1};
void lcnelTaxtak(int figur, int row, int col, int ind)
{if (figur > 0)
	{figurner[row][col] = wpahanj[ind];}
	else
	{figurner[row][col] = bpahanj[ind];}}

void dnelFigur(int fig, int ind)
{int tox, syun;
	srand(time(NULL));
lb1:
	tox = rand() % 8;
	syun = rand() % 8;
	if (figurner[tox][syun] == 0)
	{if (fig == 7 || fig == -7)
		{if (fig>0)
			{if (wb1_tox != -1) 
				{if (((tox + syun) % 2) == ((wb1_tox + wb1_syun) % 2))
					{goto lb1;}
					else
					{figurner[tox][syun] = fig;
						lcnelTaxtak(fig, tox, syun, ind);}
				}
				else
				{
					figurner[tox][syun] = fig;

					wb1_tox = tox;
					wb1_syun = syun;
					lcnelTaxtak(fig, tox, syun, ind);
				}
			}

			if (fig<0)
			{
				if (bb1_tox != -1)
				{
					if (((tox + syun) % 2) == ((bb1_tox + bb1_syun) % 2))
					{
						goto lb1;
					}
					else
					{
						figurner[tox][syun] = fig;

						lcnelTaxtak(fig, tox, syun, ind);
					}

				}
				else
				{
					figurner[tox][syun] = fig;

					bb1_tox = tox;
					bb1_syun = syun;
					lcnelTaxtak(fig, tox, syun, ind);
				}
			}

		}
		else
		{
			if (fig == 1 || fig == -1)
			{
				if (tox == 0 || tox == 7)
				{
					goto lb1;

				}
				else
				{
					figurner[tox][syun] = fig;

					lcnelTaxtak(fig, tox, syun, ind);

				}
			}
			else 
			{
				figurner[tox][syun] = fig;

				lcnelTaxtak(fig, tox, syun, ind);
			}
		}
	}
	else
	{
		goto lb1;
	}
}

void lcnelBoard()
{
	for (int i = 0; i < 16; i++)
	{
		dnelFigur(wpahanj[i], i);


	}
	for (int i = 0; i < 16; i++)
	{
		dnelFigur(bpahanj[i], i);

	}


}
void checkFields(int r, int c, int fig)
{
	if (fig == 10)
	{
		wharvac[r][c] = 0;
		for (int i = r - 1; i< r + 2; i++)
		{
			if (i < 0) continue;
			if (i > 7) break;
			for (int j = c - 1; j<c + 2; j++)
			{
				if (j < 0) continue;
				if (j > 7) break;
				if (i != r || j != c)
				{
					if (figurner[i][j] == 0||figurner[i][j]<0){
					wharvac[i][j] = 1;
					}
				}
			}
		}
	}
	int s;
	if (fig == 7)
	{
		wharvac[r][c] = 0;
		s = c;
		for (int i = r - 1; i >= 0; i--)
		{
			s++;
			if (s > 7) break;
			else
			{

				if (figurner[i][s] > 0)
				{
					break;
				}
				else

				if (figurner[i][s] < 0)
				{
					wharvac[i][s] = 1;
					break;
				}
								
				else
				{
					wharvac[i][s] = 1;
				}
			}

		}
		s = c;
		for (int i = r - 1; i >= 0; i--)
		{
			s--;
			if (s < 0) break;
			else
			{
				if (figurner[i][s] > 0)
				{
					break;
				}
				else
		
				if (figurner[i][s] < 0)
				{
					wharvac[i][s] = 1;
					break;
				}
				else
				{
					wharvac[i][s] = 1;
				}
			}

		}
		
		s = c;
		for (int i = r + 1; i < 8; i++)
		{
			s++;
			if (s > 7) break;
			else
			{
		
				if (figurner[i][s] > 0)
				{
					break;
				}
				else
		
				if (figurner[i][s] < 0)
				{
					wharvac[i][s] = 1;
					break;
				}
				else
				{
					wharvac[i][s] = 1;
				}
			}

		}
	
		s = c;
		for (int i = r + 1; i < 8; i++)
		{
			s--;
			if (s < 0) break;
			else
			{
	
				if (figurner[i][s] > 0)
				{
					break;
				}
				else
	
				if (figurner[i][s] < 0)
				{
					wharvac[i][s] = 1;
					break;
				}
				else
				{
					wharvac[i][s] = 1;
				}
			}

		}
	}
	if (fig == 8)
	{
		wharvac[r][c] = 0;
	
		s = c;
		for (int i = r - 1; i >= 0; i--)
		{
	
			if (figurner[i][c] > 0)
			{
				break;
			}
			else
	
			if (figurner[i][c] < 0)
			{
				wharvac[i][c] = 1;
				break;
			}
			else
			{
				wharvac[i][c] = 1;
			}
		}
	
		s = c;
		for (int i = r + 1; i < 8; i++)
		{
		if (figurner[i][c] > 0)
			{
				break;
			}
			else
			if (figurner[i][c] < 0)
			{
				wharvac[i][c] = 1;
				break;
			}
			else
			{
				wharvac[i][c] = 1;
			}
		}
		s = r;
		for (int i = c + 1; i < 8; i++)
		{

			if (figurner[r][i] > 0)
			{
				break;
			}
			else

			if (figurner[r][i] < 0)
			{
				wharvac[r][i] = 1;
				break;
			}
			else
			{
				wharvac[r][i] = 1;
			}
		}
			s = r;
		for (int i = c - 1; i >=0; i--)
		{
			if (figurner[r][i] > 0)
			{
				break;
			}
			else
		
			if (figurner[r][i] < 0)
			{
				wharvac[r][i] = 1;
				break;
			}
			else
			{
				wharvac[r][i] = 1;
			}
		}
	}
	if (fig == 1)
	{
		wharvac[r][c] = 0;

		s = c;
		for (int i = r - 1; i >= 0; i--)
		{
			s--;
			if (s < 0) break;
			else
			{

				if (figurner[i][s] > 0)
				{
					break;
				}
				else

				if (figurner[i][s] < 0)
				{
					wharvac[i][s] = 1;
					break;
				}
				else
				{
					wharvac[i][s] = 1; break;
				}
			}

		}


		s = c;
		for (int i = r - 1; i >= 0; i--)
		{
			s++;
			if (s > 7) break;
			else
			{
			if (figurner[i][s] > 0)
				{
					break;
				}
				else
				if (figurner[i][s] < 0)
				{
					wharvac[i][s] = 1;
					break;
				}

				else
				{
					wharvac[i][s] = 1; break;
				}
			}

		}

	}
	if (fig == 6)
	{
	wharvac[r][c] = 0;
	int zr, zc;
	zr = r;
	zc = c;

	if (((zr - 2) >= 0) && ((zc + 1) < 8) && (figurner[zr - 2][zc + 1] <= 0)){ wharvac[zr - 2][zc + 1] = 1; };
	if (((zr - 2) >= 0) && ((zc - 1) >= 0) && (figurner[zr - 2][zc - 1] <= 0)){ wharvac[zr - 2][zc - 1] = 1; };
	if (((zr + 2) < 8) && ((zc + 1) < 8) && (figurner[zr + 2][zc + 1] <= 0)){ wharvac[zr + 2][zc + 1] = 1; };
	if (((zr + 2) < 8) && ((zc - 1) >= 0) && (figurner[zr + 2][zc - 1] <= 0)){ wharvac[zr + 2][zc - 1] = 1; };
	if (((zr - 1) >= 0) && ((zc - 2) >= 0) && (figurner[zr - 1][zc - 2] <= 0)){ wharvac[zr - 1][zc - 2] = 1; };
	if (((zr - 1) >= 0) && ((zc + 2) < 8) && (figurner[zr - 1][zc + 2] <= 0)){ wharvac[zr - 1][zc + 2] = 1; };
	if (((zr + 1) < 8) && ((zc - 2) >= 0) && (figurner[zr + 1][zc - 2] <= 0)){ wharvac[zr + 1][zc - 2] = 1; };
	if (((zr + 1) < 8) && ((zc + 2) < 8) && (figurner[zr + 1][zc + 2] <= 0)){ wharvac[zr + 1][zc + 2] = 1; };

	}
	if (fig == 9)
	{
		wharvac[r][c] = 0; 
		wognakan[r][c] = 2;
		int s;
			s = c;
			for (int i = r - 1; i >= 0; i--)
			{
				s++;
				if (s > 7) break;
				else
				{
					//sqan@
					if (figurner[i][s] > 0)
					{
						break;
					}
					else
						//verj sqan@
					if (figurner[i][s] < 0)
					{
						wognakan[i][s] = 2;
						wharvac[i][s] = 1;
						break;
					}

					else
					{
						wognakan[i][s] = 2;
						wharvac[i][s] = 1;
					}
				}

			}
			//levi verev
			s = c;
			for (int i = r - 1; i >= 0; i--)
			{
				s--;
				if (s < 0) break;
				else
				{
					//sqan@
					if (figurner[i][s] > 0)
					{
						break;
					}
					else
						//verj sqan@
					if (figurner[i][s] < 0)
					{
						wognakan[i][s] = 2;
						wharvac[i][s] = 1;
						break;
					}
					else
					{
						wognakan[i][s] = 2;
						wharvac[i][s] = 1;
					}
				}

			}
			//aj nerqev
			s = c;
			for (int i = r + 1; i < 8; i++)
			{
				s++;
				if (s > 7) break;
				else
				{
					//sqan@
					if (figurner[i][s] > 0)
					{
						break;
					}
					else
						//verj sqan@
					if (figurner[i][s] < 0)
					{
						wognakan[i][s] = 2;
						wharvac[i][s] = 1;
						break;
					}
					else
					{
						wognakan[i][s] = 2;
						wharvac[i][s] = 1;
					}
				}

			}
			//levi nerqev
			s = c;
			for (int i = r + 1; i < 8; i++)
			{
				s--;
				if (s < 0) break;
				else
				{
					//sqan@
					if (figurner[i][s] > 0)
					{
						break;
					}
					else
						//verj sqan@
					if (figurner[i][s] < 0)
					{
						wognakan[i][s] = 2;
						wharvac[i][s] = 1;
						break;
					}
					else
					{
						wognakan[i][s] = 2;
						wharvac[i][s] = 1;
					}
				}

			}
		//pxi verchy

		//navak
		

			//verev
			s = c;
			for (int i = r - 1; i >= 0; i--)
			{
				//sqan@
				if (figurner[i][c] > 0)
				{
					break;
				}
				else
					//verj sqan@
				if (figurner[i][c] < 0)
				{
					wognakan[i][c] = 2;
					wharvac[i][c] = 1;
					break;
				}
				else
				{
					wognakan[i][c] = 2;
					wharvac[i][c] = 1;
				}
			}
			//nerqev
			s = c;
			for (int i = r + 1; i < 8; i++)
			{
				//sqan@
				if (figurner[i][c] > 0)
				{
					break;
				}
				else
					//verj sqan@
				if (figurner[i][c] < 0)
				{
					wognakan[i][c] = 2;
					wharvac[i][c] = 1;
					break;
				}
				else
				{
					wognakan[i][c] = 2;
					wharvac[i][c] = 1;
				}
			}
			//aj
			s = r;
			for (int i = c + 1; i < 8; i++)
			{
				//sqan@
				if (figurner[r][i] > 0)
				{
					break;
				}
				else
					//verj sqan@
				if (figurner[r][i] < 0)
				{
					wognakan[r][i] = 2;
					wharvac[r][i] = 1;
					break;
				}
				else
				{
					wognakan[r][i] = 2;
					wharvac[r][i] = 1;
				}
			}
			//dzax
			s = r;
			for (int i = c - 1; i >= 0; i--)
			{
				//sqan@
				if (figurner[r][i] > 0)
				{
					break;
				}
				else
					//verj sqan@
				if (figurner[r][i] < 0)
				{
					wognakan[r][i] = 2;
					wharvac[r][i] = 1;
					break;
				}
				else
				{
					wognakan[r][i] = 2;
					wharvac[r][i] = 1;
				}
			}
		
		////////////////

	}

	//taguhu verj

	// VERJ SPITAKNERI

	
	//SEVERI SKIZB
	//arqa
	if (fig == -10)
	{
		bharvac[r][c] = 0;
		for (int i = r - 1; i< r + 2; i++)
		{
			if (i < 0) continue;
			if (i > 7) break;
			for (int j = c - 1; j<c + 2; j++)
			{
				if (j < 0) continue;
				if (j > 7) break;
				if (i != r || j != c)
				{
					if (figurner[i][j] == 0 || figurner[i][j]>0){
						bharvac[i][j] = 1;
					}
				}
			}
		}
	}//arqa finish

	//phix
	
	if (fig == -7)
	{
		bharvac[r][c] = 0;
		//verev aj
		s = c;
		for (int i = r - 1; i >= 0; i--)
		{
			s++;
			if (s > 7) break;
			else
			{
				//sqan@
				if (figurner[i][s] < 0)
				{
					break;
				}
				else
					//verj sqan@
				if (figurner[i][s] > 0)
				{
					bharvac[i][s] = 1;
					break;
				}

				else
				{
					bharvac[i][s] = 1;
				}
			}

		}
		//levi verev
		s = c;
		for (int i = r - 1; i >= 0; i--)
		{
			s--;
			if (s < 0) break;
			else
			{
				//sqan@
				if (figurner[i][s] < 0)
				{
					break;
				}
				else
					//verj sqan@
				if (figurner[i][s] > 0)
				{
					bharvac[i][s] = 1;
					break;
				}
				else
				{
					bharvac[i][s] = 1;
				}
			}

		}
		//aj nerqev
		s = c;
		for (int i = r + 1; i < 8; i++)
		{
			s++;
			if (s > 7) break;
			else
			{
				//sqan@
				if (figurner[i][s] < 0)
				{
					break;
				}
				else
					//verj sqan@
				if (figurner[i][s] > 0)
				{
					bharvac[i][s] = 1;
					break;
				}
				else
				{
					bharvac[i][s] = 1;
				}
			}

		}
		//levi nerqev
		s = c;
		for (int i = r + 1; i < 8; i++)
		{
			s--;
			if (s < 0) break;
			else
			{
				//sqan@
				if (figurner[i][s] < 0)
				{
					break;
				}
				else
					//verj sqan@
				if (figurner[i][s] > 0)
				{
					bharvac[i][s] = 1;
					break;
				}
				else
				{
					bharvac[i][s] = 1;
				}
			}

		}
	}//pxi verchy

	//navak
	if (fig == -8)
	{
		bharvac[r][c] = 0;
		//verev
		s = c;
		for (int i = r - 1; i >= 0; i--)
		{
			//sqan@
			if (figurner[i][c] < 0)
			{
				break;
			}
			else
				//verj sqan@
			if (figurner[i][c] > 0)
			{
				bharvac[i][c] = 1;
				break;
			}
			else
			{
				bharvac[i][c] = 1;
			}
		}
		//nerqev
		s = c;
		for (int i = r + 1; i < 8; i++)
		{
			//sqan@
			if (figurner[i][c] < 0)
			{
				break;
			}
			else
				//verj sqan@
			if (figurner[i][c] > 0)
			{
				bharvac[i][c] = 1;
				break;
			}
			else
			{
				bharvac[i][c] = 1;
			}
		}
		//aj
		s = r;
		for (int i = c + 1; i < 8; i++)
		{
			//sqan@
			if (figurner[r][i] < 0)
			{
				break;
			}
			else
				//verj sqan@
			if (figurner[r][i] > 0)
			{
				bharvac[r][i] = 1;
				break;
			}
			else
			{
				bharvac[r][i] = 1;
			}
		}
		//dzax
		s = r;
		for (int i = c - 1; i >= 0; i--)
		{
			//sqan@
			if (figurner[r][i] < 0)
			{
				break;
			}
			else
				//verj sqan@
			if (figurner[r][i] > 0)
			{
				bharvac[r][i] = 1;
				break;
			}
			else
			{
				bharvac[r][i] = 1;
			}
		}
	}
	// navak@ verj


	//peshki skizb
	if (fig == -1)
	{
		bharvac[r][c] = 0;
		//dzax verev
		s = c;
		for (int i = r - 1; i >= 0; i--)
		{
			s--;
			if (s < 0) break;
			else
			{
				//sqan@
				if (figurner[i][s] < 0)
				{
					break;
				}
				else
					//verj sqan@
				if (figurner[i][s] > 0)
				{
					bharvac[i][s] = 1;
					break;
				}
				else
				{
					bharvac[i][s] = 1; break;
				}
			}

		}

		// aj verev
		s = c;
		for (int i = r - 1; i >= 0; i--)
		{
			s++;
			if (s > 7) break;
			else
			{
				//sqan@
				if (figurner[i][s] < 0)
				{
					break;
				}
				else
					//verj sqan@
				if (figurner[i][s] > 0)
				{
					bharvac[i][s] = 1;
					break;
				}

				else
				{
					bharvac[i][s] = 1; break;
				}
			}

		}

	}
	//peshki verj


	//dziu skizb
	if (fig == -6)
	{
		bharvac[r][c] = 0;
		int zr, zc;
		zr = r;
		zc = c;

		if (((zr - 2) >= 0) && ((zc + 1) < 8) && (figurner[zr - 2][zc + 1] >= 0)){ bharvac[zr - 2][zc + 1] = 1; };
		if (((zr - 2) >= 0) && ((zc - 1) >= 0) && (figurner[zr - 2][zc - 1] >= 0)){ bharvac[zr - 2][zc - 1] = 1; };
		if (((zr + 2) < 8) && ((zc + 1) < 8) && (figurner[zr + 2][zc + 1] >= 0)){ bharvac[zr + 2][zc + 1] = 1; };
		if (((zr + 2) < 8) && ((zc - 1) >= 0) && (figurner[zr + 2][zc - 1] >= 0)){ bharvac[zr + 2][zc - 1] = 1; };
		if (((zr - 1) >= 0) && ((zc - 2) >= 0) && (figurner[zr - 1][zc - 2] >= 0)){ bharvac[zr - 1][zc - 2] = 1; };
		if (((zr - 1) >= 0) && ((zc + 2) < 8) && (figurner[zr - 1][zc + 2] >= 0)){ bharvac[zr - 1][zc + 2] = 1; };
		if (((zr + 1) < 8) && ((zc - 2) >= 0) && (figurner[zr + 1][zc - 2] >= 0)){ bharvac[zr + 1][zc - 2] = 1; };
		if (((zr + 1) < 8) && ((zc + 2) < 8) && (figurner[zr + 1][zc + 2] >= 0)){ bharvac[zr + 1][zc + 2] = 1; };

	}
	//dziu verj


	//taguhu skizb
	if (fig == -9)
	{
		bharvac[r][c] = 0;
		bognakan[r][c] = 3;
		/////////////////
		int s;

		//verev aj
		s = c;
		for (int i = r - 1; i >= 0; i--)
		{
			s++;
			if (s > 7) break;
			else
			{
				//sqan@
				if (figurner[i][s] < 0)
				{
					break;
				}
				else
					//verj sqan@
				if (figurner[i][s] > 0)
				{
					bognakan[i][s] = 3;
					bharvac[i][s] = 1;
					break;
				}

				else
				{
					bognakan[i][s] = 3;
					bharvac[i][s] = 1;
				}
			}

		}
		//levi verev
		s = c;
		for (int i = r - 1; i >= 0; i--)
		{
			s--;
			if (s < 0) break;
			else
			{
				//sqan@
				if (figurner[i][s] < 0)
				{
					break;
				}
				else
					//verj sqan@
				if (figurner[i][s] > 0)
				{
					bognakan[i][s] = 3;
					bharvac[i][s] = 1;
					break;
				}
				else
				{
					bognakan[i][s] = 3;
					bharvac[i][s] = 1;
				}
			}

		}
		//aj nerqev
		s = c;
		for (int i = r + 1; i < 8; i++)
		{
			s++;
			if (s > 7) break;
			else
			{
				//sqan@
				if (figurner[i][s] < 0)
				{
					break;
				}
				else
					//verj sqan@
				if (figurner[i][s] > 0)
				{
					bognakan[i][s] = 3;
					bharvac[i][s] = 1;
					break;
				}
				else
				{
					bognakan[i][s] = 3;
					bharvac[i][s] = 1;
				}
			}

		}
		//levi nerqev
		s = c;
		for (int i = r + 1; i < 8; i++)
		{
			s--;
			if (s < 0) break;
			else
			{
				//sqan@
				if (figurner[i][s] < 0)
				{
					break;
				}
				else
					//verj sqan@
				if (figurner[i][s] > 0)
				{
					bognakan[i][s] = 3;
					bharvac[i][s] = 1;
					break;
				}
				else
				{
					bognakan[i][s] = 3;
					bharvac[i][s] = 1;
				}
			}

		}
		//pxi verchy

		//navak


		//verev
		s = c;
		for (int i = r - 1; i >= 0; i--)
		{
			//sqan@
			if (figurner[i][c] < 0)
			{
				break;
			}
			else
				//verj sqan@
			if (figurner[i][c] > 0)
			{
				bognakan[i][c] = 3;
				bharvac[i][c] = 1;
				break;
			}
			else
			{
				bognakan[i][c] = 3;
				bharvac[i][c] = 1;
			}
		}
		//nerqev
		s = c;
		for (int i = r + 1; i < 8; i++)
		{
			//sqan@
			if (figurner[i][c] < 0)
			{
				break;
			}
			else
				//verj sqan@
			if (figurner[i][c] > 0)
			{
				bognakan[i][c] = 3;
				bharvac[i][c] = 1;
				break;
			}
			else
			{
				bognakan[i][c] = 3;
				bharvac[i][c] = 1;
			}
		}
		//aj
		s = r;
		for (int i = c + 1; i < 8; i++)
		{
			//sqan@
			if (figurner[r][i] < 0)
			{
				break;
			}
			else
				//verj sqan@
			if (figurner[r][i] > 0)
			{
				bognakan[r][i] = 3;
				bharvac[r][i] = 1;
				break;
			}
			else
			{
				bognakan[r][i] = 3;
				bharvac[r][i] = 1;
			}
		}
		//dzax
		s = r;
		for (int i = c - 1; i >= 0; i--)
		{
			//sqan@
			if (figurner[r][i] < 0)
			{
				break;
			}
			else
				//verj sqan@
			if (figurner[r][i] > 0)
			{
				bognakan[r][i] = 3;
				bharvac[r][i] = 1;
				break;
			}
			else
			{
				bognakan[r][i] = 3;
				bharvac[r][i] = 1;
			}
		}

		////////////////

	}

	//taguhu verj

	//SEVERI VERJ
	
}
void checkAttacs()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (figurner[i][j] != 0)
			{
				checkFields(i, j, figurner[i][j]);
			}
		}
	}

}

//!!!!!!show harvats!!!!!!!!//
void showWAtt()
{

	cout << "SPITAK TAGUHU HNARAVOR QAYLER@" << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << wtaguhi[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
	/*for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << wognakan[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << wharvac[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << figurner[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << virfigures[i][j] << " ";
		}
		cout << endl;
	}
	*/
}
//************ Harvatsneri Verj ************//


//********veradnel()-karevorner@ voch harvatsi tak dashterum**************//
void veradnel()
{

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//spitak arqa

			
			if ((figurner[i][j] == 10) && bharvac[i][j] == 1)
			{

				figurner[i][j] = 0;

				zroyacnel();
				checkAttacs();
				int tox, syun;
				srand(time(NULL));

			lb15:

				tox = rand() % 8;
				syun = rand() % 8;

				if ((figurner[tox][syun] == 0) && (bharvac[tox][syun] != 1))
				{
					figurner[tox][syun] = 10;
				}
				else
				{
					goto lb15;
				}
			}
			//spitak arqayi verj
			zroyacnel();
			checkAttacs();

			// sev arqa
			if ((figurner[i][j] == -10) && wharvac[i][j] == 1)
			{

				figurner[i][j] = 0;
				zroyacnel();
				checkAttacs();
				int tox, syun;
			srand(time(NULL));

			lb16:

				tox = rand() % 8;
				syun = rand() % 8;

				if ((figurner[tox][syun] == 0) && (wharvac[tox][syun] != 1))
				{
					figurner[tox][syun] = -10;
				}
				else
				{
					goto lb16;
				}
			}
			//sev arqayi verj
			zroyacnel();
			checkAttacs();

			//spitak taguhi
			if ((figurner[i][j] == 9) && bharvac[i][j] == 1)
			{

				figurner[i][j] = 0;
				zroyacnel();
				checkAttacs();
				int tox, syun;
			srand(time(NULL));

			lb18:

				tox = rand() % 8;
				syun = rand() % 8;

				if ((figurner[tox][syun] == 0) && (bharvac[tox][syun] != 1))
				{
					figurner[tox][syun] = 9;
				}
				else
				{
					goto lb18;
				}
			}
			//verj spitak taguhi
			zroyacnel();
			checkAttacs();

			//sev taguhi
			if ((figurner[i][j] == -9) && wharvac[i][j] == 1)
			{

				figurner[i][j] = 0;
				zroyacnel();
				checkAttacs();
				int tox, syun;
				srand(time(NULL));

			lb17:

				tox = rand() % 8;
				syun = rand() % 8;

				if ((figurner[tox][syun] == 0) && (wharvac[tox][syun] != 1))
				{
					figurner[tox][syun] = -9;
				}
				else
				{
					goto lb17;
				}
			}
			//verj sev taguhi
			zroyacnel();
			checkAttacs();
		}
	}
}

//*************verj veradnel***********************//


//**************start showboard*******************//
//makeTox() --- showboard-in entaka funkcia
void makeTox(char guyn, const wchar_t *figur)
{
	int a;
	if (figur != L"\x0020")
	{
		cout << guyn << guyn;
		a = _setmode(_fileno(stdout), _O_U8TEXT);
		wcout << figur;
		a = _setmode(_fileno(stdout), _O_TEXT);
		cout << guyn << guyn;
	}
	else
	{
		cout << guyn << guyn << guyn << guyn << guyn;
	}
}
// showBoard() --- tpum e dasht@ @st <<taxtak>> masivi aranc tramabanutyan
void showBoard()
{
	lcnelBoard();
	zroyacnel();
	checkAttacs();
	veradnel();//vor harvatsi tak chlinen
	zroyacnel();
	checkAttacs();
	tverovy_simvolnerovi();
	char phoxel = WHITE;
	//int thver = 8;
	int str;
	cout << endl << endl << endl;

	int tox = 8;
	cout << "     " << "________________________________________" << endl;
	for (int i = 1; i <= 24; i++)
	{



		str = i / 3;

		if ((i % 3 == 2) && (tox != 0))
		{
			cout << "  " << tox << " |";
			tox--;
		}
		else cout << "    |";
		for (int j = 0; j < 8; j++)
		{



			if (taxtak[str][j] != L"\x0020")
			{
				if (i % 3 == 2)	makeTox(phoxel, taxtak[str][j]);
				else makeTox(phoxel, L"\x0020");
			}
			else
			{
				makeTox(phoxel, L"\x0020");
			}

			if (phoxel == WHITE)
			{
				phoxel = BLACK;
			}
			else
			{
				phoxel = WHITE;
			}


		}
		cout << '|' << endl;
		if (i % 3 == 0)
		{
			if (phoxel == WHITE)
			{
				phoxel = BLACK;
			}
			else
			{
				phoxel = WHITE;
			}

		}


	}
	cout << "    " << "------------------------------------------" << endl;
	cout << "    " << "   a    b    c    d    e    f    g    h" << endl;
}
//verj  showBoard() ---
//**************stop showboard*******************//


////////////////////////////////////////////////////////////////////
///////////////////TAGUHI///////////////////////////////////////////

//spitak 2
//sev 3




void taguhi()
{

	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (wognakan[r][c] == 2)
			{
				int qanak;
				qanak = 0;


				/////////////////
				int s;

				//verev aj
				s = c;
				for (int i = r - 1; i >= 0; i--)
				{
					s++;
					if (s > 7) break;
					else
					{
						//sqan@
						if (figurner[i][s] > 0)
						{
							break;
						}
						else
							//verj sqan@
						if (figurner[i][s] < 0)
						{
							qanak++;
							//	wtaguhi[i][s] = 1;
							break;
						}

						else
						{
							qanak++;
							//	wtaguhi[i][s] = 1;
						}
					}

				}
				//levi verev
				s = c;
				for (int i = r - 1; i >= 0; i--)
				{
					s--;
					if (s < 0) break;
					else
					{
						//sqan@
						if (figurner[i][s] > 0)
						{
							break;
						}
						else
							//verj sqan@
						if (figurner[i][s] < 0)
						{
							qanak++;
							//	wtaguhi[i][s] = 1;
							break;
						}
						else
						{
							qanak++;
							//	wtaguhi[i][s] = 1;
						}
					}

				}
				//aj nerqev
				s = c;
				for (int i = r + 1; i < 8; i++)
				{
					s++;
					if (s > 7) break;
					else
					{
						//sqan@
						if (figurner[i][s] > 0)
						{
							break;
						}
						else
							//verj sqan@
						if (figurner[i][s] < 0)
						{
							qanak++;
							//		wtaguhi[i][s] = 1;
							break;
						}
						else
						{
							qanak++;
							//	wtaguhi[i][s] = 1;
						}
					}

				}
				//levi nerqev
				s = c;
				for (int i = r + 1; i < 8; i++)
				{
					s--;
					if (s < 0) break;
					else
					{
						//sqan@
						if (figurner[i][s] > 0)
						{
							break;
						}
						else
							//verj sqan@
						if (figurner[i][s] < 0)
						{
							qanak++;
							//wtaguhi[i][s] = 1;
							break;
						}
						else
						{
							qanak++;
							//	wtaguhi[i][s] = 1;
						}
					}

				}
				//pxi verchy

				//navak


				//verev
				s = c;
				for (int i = r - 1; i >= 0; i--)
				{
					//sqan@
					if (figurner[i][c] > 0)
					{
						break;
					}
					else
						//verj sqan@
					if (figurner[i][c] < 0)
					{
						qanak++;
						//	wtaguhi[i][c] = 1;
						break;
					}
					else
					{
						qanak++;
						//		wtaguhi[i][c] = 1;
					}
				}
				//nerqev
				s = c;
				for (int i = r + 1; i < 8; i++)
				{
					//sqan@
					if (figurner[i][c] > 0)
					{
						break;
					}
					else
						//verj sqan@
					if (figurner[i][c] < 0)
					{
						qanak++;
						//	wtaguhi[i][c] = 1;
						break;
					}
					else
					{
						qanak++;
						//	wtaguhi[i][c] = 1;
					}
				}
				//aj
				s = r;
				for (int i = c + 1; i < 8; i++)
				{
					//sqan@
					if (figurner[r][i] > 0)
					{
						break;
					}
					else
						//verj sqan@
					if (figurner[r][i] < 0)
					{
						qanak++;
						//wtaguhi[r][i] = 1;
						break;
					}
					else
					{
						qanak++;
						//	wtaguhi[r][i] = 1;
					}
				}
				//dzax
				s = r;
				for (int i = c - 1; i >= 0; i--)
				{
					if (figurner[r][i] > 0)
					{
						break;
					}
					else
					if (figurner[r][i] < 0)
					{
						qanak++;
						break;
					}
					else
					{
						qanak++;

					}
				}
				wtaguhi[r][c] = qanak;


			}
			//Severi taguhi
		/*	if (bognakan[r][c] == 3)
			{

				int qanakk;
				qanakk = 0;

				/////////////////
				int s;

				//verev aj
				s = c;
				for (int i = r - 1; i >= 0; i--)
				{
					s++;
					if (s > 7) break;
					else
					{
						//sqan@
						if (figurner[i][s] < 0)
						{
							break;
						}
						else
							//verj sqan@
						if (figurner[i][s] > 0)
						{
							qanakk++;
							break;
						}

						else
						{
							qanakk++;
						}
					}

				}
				//levi verev
				s = c;
				for (int i = r - 1; i >= 0; i--)
				{
					s--;
					if (s < 0) break;
					else
					{
						//sqan@
						if (figurner[i][s] < 0)
						{
							break;
						}
						else
							//verj sqan@
						if (figurner[i][s] > 0)
						{
							qanakk++;
							break;
						}
						else
						{
							qanakk++;
						}
					}

				}
				//aj nerqev
				s = c;
				for (int i = r + 1; i < 8; i++)
				{
					s++;
					if (s > 7) break;
					else
					{
						//sqan@
						if (figurner[i][s] < 0)
						{
							break;
						}
						else
							//verj sqan@
						if (figurner[i][s] > 0)
						{
							qanakk++;
							break;
						}
						else
						{
							qanakk++;
						}
					}

				}
				//levi nerqev
				s = c;
				for (int i = r + 1; i < 8; i++)
				{
					s--;
					if (s < 0) break;
					else
					{
						//sqan@
						if (figurner[i][s] < 0)
						{
							break;
						}
						else
							//verj sqan@
						if (figurner[i][s] > 0)
						{
							qanakk++;
							break;
						}
						else
						{
							qanakk++;
						}
					}

				}
				//pxi verchy

				//navak


				//verev
				s = c;
				for (int i = r - 1; i >= 0; i--)
				{
					//sqan@
					if (figurner[i][c] < 0)
					{
						break;
					}
					else
						//verj sqan@
					if (figurner[i][c] > 0)
					{
						qanakk++;
						break;
					}
					else
					{
						qanakk++;
					}
				}
				//nerqev
				s = c;
				for (int i = r + 1; i < 8; i++)
				{
					//sqan@
					if (figurner[i][c] < 0)
					{
						break;
					}
					else
						//verj sqan@
					if (figurner[i][c] > 0)
					{
						qanakk++;
						break;
					}
					else
					{
						qanakk++;
					}
				}
				//aj
				s = r;
				for (int i = c + 1; i < 8; i++)
				{
					//sqan@
					if (figurner[r][i] < 0)
					{
						break;
					}
					else
						//verj sqan@
					if (figurner[r][i] > 0)
					{
						qanakk++;
						break;
					}
					else
					{
						qanakk++;
					}
				}
				//dzax
				s = r;
				for (int i = c - 1; i >= 0; i--)
				{
					//sqan@
					if (figurner[r][i] < 0)
					{
						break;
					}
					else
						//verj sqan@
					if (figurner[r][i] > 0)
					{
						qanakk++;
						break;
					}
					else
					{
						qanakk++;
					}
				}
				btaguhi[r][c] = qanakk;
			}*/
		}
		
	}
		
}

void copy()
{
	for (int l = 0; l < 8; l++)
	{
		for (int q = 0; q < 8; q++)
		{
			virfigures[l][q] = figurner[l][q];
		}
	}
}
void megpz()
{
	for (int l = 0; l < 8; l++)
	{
		for (int q = 0; q < 8; q++)
		{
			//if (figurner[l][q] == -9){ copy(); figurner[l][q] = 0; }
			if (figurner[l][q] == 9 ){ copy(); figurner[l][q] = 0; }
			if (wognakan[l][q] == 2){ taguhi(); }
		//	if (bognakan[l][q] == 3){ taguhi(); }

		}
	}
	
}

int main()
{
	showBoard();
	megpz();
	showWAtt();
	return 0;
}