#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#define SIZE 1024 * 1024

int main()
{
	int shmDesc = shm_open("/test.shm", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);

	ftruncate(shmDesc, SIZE);

	unsigned char *data = static_cast<unsigned char*>(mmap(NULL, SIZE, PROT_WRITE, 
		MAP_SHARED, shmDesc, 0));

	for (size_t i = 0; i < SIZE; i++)
	{
		data[i] = 13;
	}

	munmap(data, SIZE);
}
