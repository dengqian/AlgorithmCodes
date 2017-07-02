#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <thread>
#include <mutex>
#include <functional>
#include <string> 
#include <condition_variable>
#include <deque>
#include <vector>
#include <memory>

#include "nocopyable.h"

using namespace std;

class ThreadPool : public nocopyable
{
public:
	typedef function<void()> Task;
	ThreadPool(const string& name=string());
	~ThreadPool();

	void start(int numThreads);
	void stop();
	void run(const Task& f);
	void setMaxQueueSize(int maxSize){
		_maxQueueSize = maxSize;
	}
private:
	bool isFull();
	void runInThread();
	Task take();

	mutex _mutex;
	string _name;
	vector<thread> _threads;
	deque<Task> _queue; 
	size_t _maxQueueSize;
	bool _isRunning;
	condition_variable _notEmpty;
	condition_variable _notFull;

};

#endif