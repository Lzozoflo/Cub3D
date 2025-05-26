
#include <math.h>

int main()
{
	float pos_x= 3.6;
	float pos_y= 3.4;
	int		tile_size = 50;//window size/ by something to know

	int	pos_px_x= roundf((pos_x - 2.5) * (float)tile_size);
	int	pos_px_y= roundf((pos_y - 2.5) * (float)tile_size);
	int	pos_px_xmax= roundf((pos_x + 2.5) * (float)tile_size);
	int	pos_px_ymax= roundf((pos_y + 2.5) * (float)tile_size);
	printf("x %d\ny %d\n", pos_px_x, pos_px_y);
	printf("xm %d\nym %d", pos_px_xmax, pos_px_ymax);// thit its the pos in the tab
}
