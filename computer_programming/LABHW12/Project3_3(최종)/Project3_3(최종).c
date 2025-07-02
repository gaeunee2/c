#define _CRT_SECURE_NO_WARNINGS
#define MAX_VIDEO 100 
#define MAX_CUST 200
#define MAX_CHAR 100
#include <stdio.h> 
#include <string.h> 

typedef struct {
	char title[MAX_CHAR];
	int qty; // 수량
} VideoInfo;

typedef struct {
	int custId; // 고객 id : 1, 2, 3 
	char title[MAX_CHAR];
} RentInfo;

void printAllVideo(VideoInfo videoList[], int videoCount)
{
	int i;
	printf("Video제목\t수량\n");
	printf("-----------------------\n");
	for (i = 0; i < videoCount; i++)
		printf("%s\t%d\n", videoList[i].title, videoList[i].qty);
}

void purchaseVideo(VideoInfo videoList[], int* videoCountPtr, char* title, int qty)
{
	strcpy(videoList[*videoCountPtr].title, title);
	videoList[*videoCountPtr].qty = qty;
	(*videoCountPtr)++;
}

int searchVideoByTitle(VideoInfo* videoList, int videoCount, char* title)
{
	int i;
	for (i = 0; i < videoCount; i++)
		if (strcmp(videoList[i].title, title) == 0)
			return i;
	return -1;
}

void rentVideo(VideoInfo* videoList, int videoCount, RentInfo* rentList, int* rentCount, char* title, int custId)
{
	int index = searchVideoByTitle(videoList, videoCount, title);
	if (index != -1 && videoList[index].qty > 0) {
		rentList[*rentCount].custId = custId;
		strcpy(rentList[*rentCount].title, title);
		videoList[index].qty--;
		(*rentCount)++;
	}
	else
		printf("대여 안됨\n");
}

void printAllRent(RentInfo* rentList, int rentCount)
{
	int i;
	printf("고객id\tVideo제목\n");
	printf("-----------------------\n");
	for (i = 0; i < rentCount; i++)
		printf("%d\t%s\n", rentList[i].custId, rentList[i].title);
}

void readVideo(VideoInfo videoList[], int* videoCountPtr)
{
	FILE* fp;
	VideoInfo video;

	if ((fp = fopen("video.txt", "r")) == NULL) {
		printf("입력 파일 오픈 실패\n");
		exit(1);
	}

	while (fscanf(fp, "%d %s", &video.qty, video.title) != EOF) {
		videoList[*videoCountPtr] = video;
		(*videoCountPtr)++;
	}

	fclose(fp);
}

void writeVideo(VideoInfo videoList[], int videoCount)
{
	FILE* fp;
	int i;
	if ((fp = fopen("video.txt", "w")) == NULL) {
		printf("출력 파일 오픈 실패\n");
		exit(1);
	}
	for (i = 0; i < videoCount; i++)
		fprintf(fp, "%d %s\n", videoList[i].qty, videoList[i].title);
	fclose(fp);
}

void writeRent(RentInfo rentList[], int rentCount)
{
	FILE* fp;
	int i;
	fp = fopen("rent.txt", "w");
	if (fp == NULL) {
		printf("출력 파일 오픈 실패\n"); exit(1);
	}
	for (i = 0; i < rentCount; i++)
		fprintf(fp, "%d %s\n", rentList[i].custId, rentList[i].title);
	fclose(fp);
}

int main(void)
{
	int videoCount = 0;
	VideoInfo videoList[MAX_VIDEO];
	int rentCount = 0; // 현재 대출 건수는 0
	RentInfo rentList[MAX_CUST];

	char title[MAX_CHAR];
	int qty, custId;
	int choice;
	int indexSearched;

	readVideo(videoList, &videoCount);

	printf("1(All Video 출력), 2(구입), 3(검색), 4(대여), 5(All 대여정보 출력), 6(종료): ");
	scanf("%d", &choice);
	while (choice != 6) {
		switch (choice) {
		case 1: printAllVideo(videoList, videoCount); break;
		case 2:
			printf("Enter video 제목: ");
			scanf("%s", title);
			printf("Enter video 수량: ");
			scanf("%d", &qty);
			purchaseVideo(videoList, &videoCount, title, qty); break;
		case 3:
			printf("Enter video 제목: ");
			scanf("%s", title);
			if ((indexSearched = searchVideoByTitle(videoList, videoCount, title)) == -1)
				printf("그런 비디오는 없습니다.\n");
			else if (videoList[indexSearched].qty == 0)
				printf("다 대여중입니다.\n");
			else
				printf("대여 가능합니다.\n"); break;
		case 4:
			printf("Enter video 제목: ");
			scanf("%s", title);
			printf("Enter 고객 id: ");
			scanf("%d", &custId);
			rentVideo(videoList, videoCount, rentList, &rentCount, title, custId);
			break;
		case 5:
			printAllRent(rentList, rentCount);
			break;
		}
		printf("1(All Video 출력), 2(구입), 3(검색), 4(대여), 5(All 대여정보 출력), 6(종료): ");
		scanf("%d", &choice);
	}
	writeVideo(videoList, videoCount);
	writeRent(rentList, rentCount);
}