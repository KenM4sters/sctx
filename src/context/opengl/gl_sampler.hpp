#ifndef MAMMOTH_2D_GL_SAMPLER_HPP
#define MAMMOTH_2D_GL_SAMPLER_HPP

#include <sctx.hpp>

namespace mt 
{

class GLSampler final : public Sampler
{
public:
    explicit GLSampler() noexcept
        : m_addressModeS{GL_CLAMP_TO_EDGE},
        m_addressModeT{GL_CLAMP_TO_EDGE},
        m_addressModeR{GL_CLAMP_TO_EDGE},
        m_minFilter{GL_LINEAR},
        m_magFilter{GL_LINEAR} 
    {}

    virtual void create(
        GLenum addressModeS,
        GLenum addressModeT,
        GLenum addressModeR,
        GLenum minFilter,
        GLenum magFilter
    ) override;

    virtual void update(
        GLenum addressModeS,
        GLenum addressModeT,
        GLenum addressModeR,
        GLenum minFilter,
        GLenum magFilter
    ) override;

    virtual void detroy() override;

    [[nodiscard]] constexpr GLuint gl_handle() const { return m_glHandle; }

    [[nodiscard]] constexpr GLenum address_mode_s() const { return m_addressModeS; }

    [[nodiscard]] constexpr GLenum address_mode_t() const { return m_addressModeT; }

    [[nodiscard]] constexpr GLenum address_mode_r() const { return m_addressModeR; }

    [[nodiscard]] constexpr GLenum min_filter() const { return m_minFilter; }

    [[nodiscard]] constexpr GLenum mag_filter() const { return m_magFilter; }
    
private:
    GLuint m_glHandle;
    GLenum m_addressModeS;
    GLenum m_addressModeT;
    GLenum m_addressModeR;
    GLenum m_minFilter;
    GLenum m_magFilter;
};
}

#endif