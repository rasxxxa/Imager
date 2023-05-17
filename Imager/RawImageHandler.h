#pragma once
#include <vector>
#include <string>
#include <iostream>

struct Image
{
	std::vector<char> m_imageData;
	unsigned int m_width;
	unsigned int m_height;
	unsigned long long m_size;
	unsigned short m_channels;
};

class RawImageHandler
{
public:
	RawImageHandler() = default;
	Image LoadImageFile(const std::string& path);
};

