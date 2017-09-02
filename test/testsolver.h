#ifndef TESTSOLVER_H
#define TESTSOLVER_H

#include "solver/solver.h"
#include "loader/fileloader.h"
#include <iostream>
#include <time.h>

void display(QVector< QVector<int> > t) {
	for(int i = 0; i < t.size(); ++i) {
		for(int j = 0; j < t[i].size(); ++j) {
			std::cout << t[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void logNodeInfo(ListNode* node, int r) {
	qDebug() << "node" << r;
	qDebug() << node->up << node->down << node->left << node->right << node ->rowNum << node->colNum << node->size << node->removed;
}

void testSolver() {
	FileLoader fl("./mat10.txt");
	QVector< QVector<int> > mat = fl.load();
	display(mat);
	qDebug() << "finish load mat";

	clock_t start, finish;
	double timeuse = 0;
	Solver sol;
	QVector< QVector< QVector<int> > > ans;
	for(int i = 0; i < 1000; ++i){
	start = clock();
	ans = sol(mat);
	finish = clock();
	timeuse+=(double)(finish - start) / CLOCKS_PER_SEC;
	}
	qDebug()<< "time use" << timeuse/1000 <<"s";

	for(QVector< QVector<int> > t : ans) {
		display(t);
	}
}

#endif // TESTSOLVER_H
