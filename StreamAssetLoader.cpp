#include "StreamAssetLoader.h"
#include "TextureManager.h"

#include <vector>

#include "IExecutionEvent.h"

StreamAssetLoader::StreamAssetLoader(String path, IExecutionEvent* executionEvent)
{
	this->path = path;
	this->execEvent = executionEvent;

}

StreamAssetLoader::~StreamAssetLoader()
{

}

void StreamAssetLoader::run()
{

	//IETThread::sleep(200);

	TextureManager::getInstance()->instantiateAsTexture(this->path, "wew", true);

	this->execEvent->onFinishedExecution();
	delete this;
}
