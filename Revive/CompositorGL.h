#pragma once

#include "CompositorBase.h"

#include <GL/glew.h>
#include <openvr.h>

class CompositorGL :
	public CompositorBase
{
public:
	CompositorGL();
	virtual ~CompositorGL();

	virtual vr::EGraphicsAPIConvention GetAPI() { return vr::API_OpenGL; };

	// Texture Swapchain
	virtual ovrResult CreateTextureSwapChain(const ovrTextureSwapChainDesc* desc, ovrTextureSwapChain* out_TextureSwapChain);
	virtual void DestroyTextureSwapChain(ovrTextureSwapChain chain);

	// Mirror Texture
	virtual ovrResult CreateMirrorTexture(const ovrMirrorTextureDesc* desc, ovrMirrorTexture* out_MirrorTexture);
	virtual void DestroyMirrorTexture(ovrMirrorTexture mirrorTexture);
	virtual void RenderMirrorTexture(ovrMirrorTexture mirrorTexture);

protected:
	static GLenum TextureFormatToInternalFormat(ovrTextureFormat format);
	static GLenum TextureFormatToGLFormat(ovrTextureFormat format);
};