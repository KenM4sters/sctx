#ifndef MAMMOTH_2D_GRAPHICS_CONTEXT_HPP
#define MAMMOTH_2D_GRAPHICS_CONTEXT_HPP


#include <sctx/sctx.hpp>


namespace mt 
{ 

class IGraphicsContext 
{
public:
    explicit IGraphicsContext() noexcept {}

    virtual ~IGraphicsContext() {}

    IGraphicsContext(const IGraphicsContext& other) = delete;
    IGraphicsContext& operator=(const IGraphicsContext& other) = delete;
    IGraphicsContext(IGraphicsContext&& other) = default;
    IGraphicsContext& operator=(IGraphicsContext&& other) = default;

    virtual void init(const GraphicsSettings& settings) = 0;

    virtual void shutdown() = 0;
    
    [[nodiscard]] virtual WindowHandle& getWindow() = 0;


    [[nodiscard]] virtual VertexBufferHandle createVertexBuffer(
        Memory memory
    ) = 0;

    [[nodiscard]] virtual IndexBufferHandle createIndexBuffer(
        Memory memory
    ) = 0;

    [[nodiscard]] virtual UniformBufferHandle createUniformBuffer(
        Memory memory
    ) = 0;

    [[nodiscard]] virtual ProgramHandle createProgram(
        const char* vertPath, 
        const char* fragPath
    ) = 0;

    [[nodiscard]] virtual TextureHandle createTexture(
        TargetDimension target, 
        uint32_t level, 
        ArrayInternalFormat internalFormat, 
        uint32_t width, 
        uint32_t height, 
        Format format, 
        ValueType type, 
        uint32_t nMipMaps, 
        SamplerHandle& sampler
    ) = 0;

    [[nodiscard]] virtual SamplerHandle createSampler(
        SamplerAddressMode addressModeS, 
        SamplerAddressMode addressModeT, 
        SamplerAddressMode addressModeU, 
        SamplerFilterMode minFilter, 
        SamplerFilterMode magFilter
    ) = 0;

    [[nodiscard]] virtual FrameBufferHandle createFrameBuffer(
        const FrameBufferAttachment* attachments, 
        size_t count
    ) = 0;
        
    [[nodiscard]] virtual VertexInputHandle createVertexInput(
        const VertexBufferHandle& vbuffer, 
        const VertexLayoutHandle& layout, 
        const IndexBufferHandle* ibuffer
    ) = 0;

    virtual void begin(
        const FrameBufferHandle* frameBuffer,
        uint32_t flags
    ) = 0;

    virtual void end() = 0;

    virtual void submit(
        const VertexInputHandle& vInput, 
        const ShaderHandle& shader
    ) = 0;
};

};

#endif
