#ifndef SKELETON_DEPTH_H
#define SKELETON_DEPTH_H

#include <OpenNI.h>
#include "MWClosestPoint.h"
#include <opencv2/highgui.hpp>

#define MAX_DEPTH 10000

class SkeletonDepth {
    private:
	int width, height;
	int subSample;
	float rgb[3];
	int diff_w;
	int diff_h;
	int diff;
	int lineSize;
	int max;
	float maxDiff;
	float dist;
	closest_point::IntPoint3D closest;
	float m_pDepthHist[MAX_DEPTH];

	const float * paintDepthCopyPixel(const openni::DepthPixel* pDepth, int x, int y, cv::Mat * skel);
	void setDiffH(int d);
	void setDiffW(int d);

    public:
	SkeletonDepth(int, int, int);
	void paintDepthCopy(openni::RGB888Pixel*m_pTexMap, openni::VideoFrameRef depthFrame, cv::Mat * binarized);
	void prepareAnalisa(const closest_point::IntPoint3D& closest);
};


#endif // SKELETON_DEPTH_H