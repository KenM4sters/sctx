#include "gl_sampler.hpp"


#include <context/opengl/gl_context.hpp>

namespace mt 
{

void GLSampler::create(GLenum addressModeS, GLenum addressModeT, 
    GLenum addressModeR, GLenum minFilter, GLenum magFilter
) 
{
    m_addressModeS = addressModeS;
    m_addressModeT = addressModeT;
    m_addressModeR = addressModeR;
    m_minFilter = minFilter;
    m_magFilter = magFilter;

    GL_CHECK(glGenSamplers(1, &m_glHandle));
    GL_CHECK(glBindSampler(1, m_glHandle));

    GL_CHECK(glSamplerParameteri(m_glHandle, GL_TEXTURE_WRAP_S, m_addressModeS));
    GL_CHECK(glSamplerParameteri(m_glHandle, GL_TEXTURE_WRAP_T, m_addressModeT));
    GL_CHECK(glSamplerParameteri(m_glHandle, GL_TEXTURE_WRAP_R, m_addressModeR));
    GL_CHECK(glSamplerParameteri(m_glHandle, GL_TEXTURE_MIN_FILTER, m_magFilter));
    GL_CHECK(glSamplerParameteri(m_glHandle, GL_TEXTURE_MAG_FILTER, m_magFilter));
    
    GL_CHECK(glBindSampler(0, m_glHandle));
}

void GLSampler::update(GLenum addressModeS, GLenum addressModeT, 
    GLenum addressModeR, GLenum minFilter, GLenum magFilter
) 
{
    m_addressModeS = addressModeS;
    m_addressModeT = addressModeT;
    m_addressModeR = addressModeR;
    m_minFilter = minFilter;
    m_magFilter = magFilter;

    GL_CHECK(glBindSampler(1, m_glHandle));

    GL_CHECK(glSamplerParameteri(m_glHandle, GL_TEXTURE_WRAP_S, m_addressModeS));
    GL_CHECK(glSamplerParameteri(m_glHandle, GL_TEXTURE_WRAP_T, m_addressModeT));
    GL_CHECK(glSamplerParameteri(m_glHandle, GL_TEXTURE_WRAP_R, m_addressModeR));
    GL_CHECK(glSamplerParameteri(m_glHandle, GL_TEXTURE_MIN_FILTER, m_magFilter));
    GL_CHECK(glSamplerParameteri(m_glHandle, GL_TEXTURE_MAG_FILTER, m_magFilter));
    
    GL_CHECK(glBindSampler(0, m_glHandle));
}

void GLSampler::detroy() 
{
    glDeleteSamplers(1, &m_glHandle);
}

}