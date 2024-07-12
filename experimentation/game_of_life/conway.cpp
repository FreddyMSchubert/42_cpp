#include <algorithm>
#include <vector>
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h> // for usleep

typedef std::vector<std::vector<bool> > BoolGrid;

int	get_grid_size()
{
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if (w.ws_col < w.ws_row)
		return w.ws_col;
	return w.ws_row;
}

BoolGrid	create_grid(int size)
{
	return BoolGrid(size, std::vector<bool>(size, false));
}

void	initialize_grid_randomly(BoolGrid& grid)
{
	srand(static_cast<unsigned int>(time(0)));

	for (int i = 0; i < (int)grid.size(); i++)
		for (int j = 0; j < (int)grid[i].size(); j++)
			grid[i][j] = rand() % 2 == 1;
}

int	count_live_neighbors(const BoolGrid& grid, int x, int y)
{
	int live_count = 0;
	int size = grid.size();

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0)	continue;

			int ni = x + i;
			int nj = y + j;

			if (ni >= 0 && ni < size && nj >= 0 && nj < size)
				if (grid[ni][nj])
					live_count++;
		}
	}

	return	live_count;
}

void	apply_conway_rules(const BoolGrid& prevGrid, BoolGrid& nextGrid)
{
	int size = prevGrid.size();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int live_neighbors = count_live_neighbors(prevGrid, i, j);

			if (prevGrid[i][j])
			{
				if (live_neighbors < 2 || live_neighbors > 3)
					nextGrid[i][j] = false;
				else
					nextGrid[i][j] = true;
			}
			else
			{
				if (live_neighbors == 3)
					nextGrid[i][j] = true;
				else
					nextGrid[i][j] = false;
			}
		}
	}
}

void	print_map(BoolGrid grid)
{
	system("clear"); // doesnt work on windows, use cls there

	for (size_t i = 0; i < grid.size(); i++)
	{
		for (size_t j = 0; j < grid[i].size(); j++)
			std::cout << (grid[i][j] ? "🟥" : "⬜️") << ' ';
		std::cout << '\n';
	}
	std::cout << std::flush;
}

bool	check_done(BoolGrid prevGrid, BoolGrid nextGrid)
{
	int size = prevGrid.size();

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (prevGrid[i][j] != nextGrid[i][j])
				return false;
	return true;
}

int	main()
{
	int	size = get_grid_size();
	BoolGrid prevGrid = create_grid(size);
	BoolGrid nextGrid = create_grid(size);
	initialize_grid_randomly(prevGrid);
	bool running = true;

	while (running)
	{
		apply_conway_rules(prevGrid, nextGrid);
		print_map(nextGrid);
		usleep(200000); // 200 ms
		running = !check_done(prevGrid, nextGrid);
		std::swap(prevGrid, nextGrid);
	}
}
