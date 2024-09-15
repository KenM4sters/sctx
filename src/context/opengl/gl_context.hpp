#ifndef MAMMOTH_2D_GL_CONTEXT_HPP
#define MAMMOTH_2D_GL_CONTEXT_HPP



#define GL_CHECK(stmt) do { \
    stmt; \
    checkGLError(#stmt, __FILE__, __LINE__); \
} while (0)


namespace mt 
{
std::string getGLErrorString(GLenum error) noexcept;

void checkGLError(const char* stmt, const char* file, int line);
/**
 * @brief OpenGL context reponsible for implementating all methods belonging to IGraphicContext
 * for the OpenGL api. Given the simplicity of OpenGL, there's isn't much else going on here besides
 * functions that manage GL objects, a window and a state manager. For a more sophisticated 
 * GraphicsContext, see @ref VKGraphicsContext.
 */
class GLGraphicsContext final : public IGraphicsContext 
{
public:
    explicit GLGraphicsContext() noexcept
        : m_window{nullptr}
    {}

    virtual ~GLGraphicsContext();

    virtual void init(const GraphicsSettings& settings) override;

    virtual void shutdown() override;

    [[nodiscard]] virtual WindowHandle& getWindow() override;

    [[nodiscard]] virtual VertexBufferHandle createVertexBuffer(Memory memory) override;

    [[nodiscard]] virtual IndexBufferHandle createIndexBuffer(Memory memory) override;

    [[nodiscard]] virtual UniformBufferHandle createUniformBuffer(Memory memory) override;

    [[nodiscard]] virtual ProgramHandle createProgram(const char* vertPath, const char* fragPath) override;

    [[nodiscard]] virtual TextureHandle createTexture(TargetType target, uint32_t level, InternalFormat internalFormat, uint32_t width, uint32_t height, Format format, ValueType type, uint32_t nMipMaps, SamplerHandle& sampler) override;

    [[nodiscard]] virtual SamplerHandle createSampler(SamplerAddressMode addressModeS, SamplerAddressMode addressModeT, SamplerAddressMode addressModeU, SamplerFilterMode minFilter, SamplerFilterMode magFilter) override;

    [[nodiscard]] virtual FrameBufferHandle createFrameBuffer(const FrameBufferAttachment* attachments, size_t count) override;

    [[nodiscard]] virtual ResourceHandle createResource(std::string name, ResourceType type, Memory memory) override;
    
    [[nodiscard]] virtual ShaderHandle createShader(ProgramHandle& program, Resource* resources, size_t count) override;
    
    [[nodiscard]] virtual VertexInputHandle createVertexInput(const VertexBufferHandle& vbuffer, const VertexLayoutHandle& layout, const IndexBufferHandle* ibuffer) override;

    virtual void begin(const FrameBufferHandle* frameBuffer, uint32_t flags) override;

    virtual void end() override;

    virtual void submit(const VertexInputHandle& vInput, const ShaderHandle& shader) override;

private:
    WindowHandle m_window;
};

}

#endif