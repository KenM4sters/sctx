#ifndef MAMMOTH_2D_MAMMOTH_HPP
#define MAMMOTH_2D_MAMMOTH_HPP

#include <glad/gl.h>

#include <iostream>


#define MT_HANDLE(Type) typedef std::shared_ptr<Type> Type##Handle;                                                      
     
namespace mt 
{

class VertexBuffer;
class IndexBuffer;
class UniformBuffer;
class Program;
class Texture;
class Sampler;
class FrameBuffer;
class Resource;
class Shader;
class VertexInput;
class VertexLayout;
class Window;

MT_HANDLE(VertexBuffer);
MT_HANDLE(IndexBuffer);
MT_HANDLE(UniformBuffer);
MT_HANDLE(Program);
MT_HANDLE(Texture);
MT_HANDLE(Sampler);
MT_HANDLE(FrameBuffer);
MT_HANDLE(Resource);
MT_HANDLE(Shader);
MT_HANDLE(VertexLayout);
MT_HANDLE(VertexInput);
MT_HANDLE(Window);

/**
 * @brief Rendering API of choice. Eventually this will cover OpenGL, Vulka, Metal and DX12,
 * but for now only OpenGL and Vulkan are being supported.
 */
enum class GraphicsBackend 
{
    OpenGL
};


/**
 * @brief Specifies how the sampler will handle texture coordinates outside of the [0, 1]
 * range.
 */
enum class SamplerAddressMode
{
    Repeat,                 ///< Wraps back around to [0, 1]
    MirroredRepeat,         ///< Same as repeat, but reflects the texture.
    ClampToEdge,            ///< Stretches the texture to the edge (ideal in most situations).
    ClampToBorder           ///< 
};


/**
 * @brief Specifies how the sampler will handle texture coordinates that do not map directly
 * to a texel, which can happen when the image has been scaled. 
 */
enum class SamplerFilterMode 
{
    Nearest,                ///< Selects the closest texel (pixelated look).
    Linear,                 ///< Linearly interpolates between relative texels (smooth look).
    MipMapNearest,          ///< Selects the closest texel (pixelated look).
    MipMapLinear            ///< Linearly interpolates between relative texels (smooth look).
};




/**
 * @brief
 */
enum class TargetType 
{
    Texture2D,
    TextureCube
};


/**
 * @brief 
 */
enum class InternalFormat 
{
    R32,
    R32F,
    RG32,
    RG32F,
    RGB32,
    RGB32F,
    RGBA32,
    RGBA32F,
    Depth24Stencil8
};


/**
 * @brief
 */
enum class Format 
{
    RG,
    RGB,
    RGBA,
    DepthStencil
};


/**
 * @brief Specifies the different types of frame buffer attachments.
 * @note Color0 represents the 1st color attachment.
 */
enum class Attachment 
{
    Color0,
    Color1,
    Color2,
    Color3,
    Depth,
    Stencil,
    DepthStencil
};


/**
 * @brief An exhaustive list of the possible attributes. Names are important to match in DX12 
 * so these enum types act as indexes into an array of strings that correspond to the names
 * in shaders.
 * 
 * You should use these types regardless of the GraphicsBackend for consistency.
 */
enum class Attribute 
{
    Position,
    Normal,
    Tangent,
    BiTangent,
    Weight,
    Indices,
    Color,
    TexCoords
};


/**
 * @brief The possible types of a single value within the context of textures and attributes.
 * Often it's important to know whether something is an array of floats, characters or integers.
 */
enum class ValueType 
{
    UInt,
    SInt,
    UChar,
    SChar,
    Float
};


/**
 * @brief
 */
enum class ResourceType 
{
    Sampler,
    Float,
    Int,
    Vec2f,
    Vec2i,
    Vec3f,
    Vec3i,
    Vec4f,
    Vec4i,
    Mat4x4f,
    Mat3x3f
};


//============================================================================
// Flags to explicity pass single bits of information which change the
// context's behaviour.
//============================================================================


/**
 * @brief
 */
enum class TextureFlags
{
    ReadOnly = 0,
    WriteOnly = 1 << 0,
    ReadWrite = 1 << 1,
    Color = 1 << 3,
    Depth = 1 << 4,
    Stencil = 1 << 5,
};


/**
 * @brief 
 */
enum class VertexBufferFlags 
{
    Static = 0,
    Dynamic = 1 << 0
};


/**
 * @brief
 */
enum class IndexBufferFlags 
{
    Static = 0,
    Dynamic = 1 << 0
};


/**
 * @brief
 */
enum class UniformBufferFlags 
{
    Static = 0,
    Dynamic = 1 << 0
};



//============================================================================
// Helper structs to encapsulate variables that should only be used in 
// conjunction width each other. These are left for the the user to create.
//============================================================================


/**
 * @brief
 */
struct GraphicsSettings 
{
    GraphicsBackend backend;
    const char* name;
    uint32_t pixelViewportWidth;
    uint32_t pixelViewportHeight;
};


/**
 * @brief Encapsulates a void pointer with a size in bytes often used to map data to buffers.
 */
struct Memory 
{
    void* data;                
    size_t byteSize;
};


/**
 * @brief
 */
struct FrameBufferAttachment 
{
    Texture* pTexture;
    Attachment attachment;
};


/**
 * @brief 
 */
struct Extent 
{
    uint32_t width;
    uint32_t height;
};


/**
 * @brief 
 */
struct Transform 
{
    float* pModel;
    size_t matrixCount;
};




/**
 * @brief
 */
struct VertexAttribute 
{
    VertexAttribute(Attribute attribute, ValueType type, size_t count)
        : type{type},
        count{count},
        byteOffset{0}
    {
        switch(type) 
        {
            case ValueType::UInt: byteSize = count * 4; break;
            case ValueType::SInt: byteSize = count * 4; break;
            case ValueType::UChar: byteSize = count * 1; break;
            case ValueType::SChar: byteSize = count * 1; break;
            case ValueType::Float: byteSize = count * 4; break;
        }
    }   
    
    ValueType type;
    size_t count;
    size_t byteOffset;
    size_t byteSize;
};


/**
 * @brief 
 */
struct VertexLayout 
{
    VertexLayout(VertexAttribute* attributes, size_t count) noexcept
        : attributes{attributes}, 
        count{count},
        stride{0} 
    {
        for(size_t i = 0; i < count; i++) 
        {
            attributes[i].byteOffset = stride;
            stride += attributes[i].byteSize;
        }   
    }

    VertexAttribute* attributes;
    size_t count;
    size_t stride;
};


/**
 * @brief
 */
class VertexBuffer 
{   
    friend class GLVertexBuffer;
public:
    VertexBuffer(const VertexBuffer& other) = delete;
    VertexBuffer& operator=(const VertexBuffer& other) = delete;

    virtual void create(Memory memory, uint32_t flags) = 0;

    virtual void update(Memory memory, size_t byteOffset) = 0;

    virtual void destroy() = 0;

    virtual ~VertexBuffer() {}
    
private:
    explicit VertexBuffer() noexcept = default;

};


/**
 * @brief
 */
class IndexBuffer 
{
    friend class GLIndexBuffer;
public:
    IndexBuffer(const IndexBuffer& other) = delete;
    IndexBuffer& operator=(const IndexBuffer& other) = delete;

    virtual void create(Memory memory, uint32_t flags) = 0;

    virtual void update(Memory memory, size_t byteOffset) = 0;

    virtual void destroy() = 0;

    virtual ~IndexBuffer() {}
    
private:
    explicit IndexBuffer() noexcept = default;

};


/**
 * @brief
 */
class UniformBuffer 
{
    friend class GLUniformBuffer;
public:
    UniformBuffer(const UniformBuffer& other) = delete;
    UniformBuffer& operator=(const UniformBuffer& other) = delete;
    UniformBuffer(UniformBuffer&& other) = default;
    UniformBuffer& operator=(UniformBuffer&& other) = default;

    virtual void create(Memory memory, uint32_t flags) = 0;

    virtual void update(Memory memory, size_t byteOffset) = 0;

    virtual void destroy() = 0;

    virtual ~UniformBuffer() {}
    
private:
    explicit UniformBuffer() noexcept = default;

};


/**
 * @brief Base class that each context provides a child class of that manages the creation
 * of a shader program from filePaths to the shader code.
 */
class Program 
{
    friend class GLProgram;
public:
    Program(const Program& other) = delete;
    Program& operator=(const Program& other) = delete;

    virtual void create(const char* vertPath, const char* fragPath) = 0;

    virtual void destroy() = 0;

    virtual ~Program() {}
    
private:
    explicit Program() noexcept = default;

};


/**
 * @brief Base class that each context provides a child of that manages the creation of a buffer 
 * on the GPU for texture data. 
 */
class Texture 
{
    friend class GLTexture;
public: 
    Texture(const Texture& other) = delete;
    Texture& operator=(const Texture& other) = delete;

	virtual void create(
        TargetType target,
        uint32_t level,
        InternalFormat internalFormat,
        uint32_t width, 
        uint32_t height, 
        Format format,
        ValueType type,
        uint32_t nMipMaps,
        uint32_t flags,
        SamplerHandle sampler
    ) = 0;

    virtual void resize(uint32_t width, uint32_t height) = 0;

    virtual void destroy() = 0;

    virtual ~Texture() {}
    
private:
    explicit Texture() noexcept = default;

};

/**
 * @brief Base class that each context provides a child of that manages the creation of a sampler
 * object that can be used for many textures that each share the same sampling properties.
 */
class Sampler 
{
    friend class GLSampler;
public: 
    Sampler(const Sampler& other) = delete;
    Sampler& operator=(const Sampler& other) = delete;

    virtual void create(
        SamplerAddressMode addressModeS,
        SamplerAddressMode addressModeT,
        SamplerAddressMode addressModeR,
        SamplerFilterMode minFilter,
        SamplerFilterMode magFilter
    ) = 0;

    virtual void update(
        SamplerAddressMode addressModeS,
        SamplerAddressMode addressModeT,
        SamplerAddressMode addressModeR,
        SamplerFilterMode minFilter,
        SamplerFilterMode magFilter
    ) = 0;

    virtual void detroy() = 0;

    virtual ~Sampler() {}
    
private:
    explicit Sampler() noexcept = default;

};



/**
 * @brief Base class that each context provides a child of that manages the creation of a FrameBuffer
 * used for rendering to offscreen buffers. 
 */
class FrameBuffer
{
    friend class GLFrameBuffer;
public:
    FrameBuffer(const FrameBuffer& other) = delete;
    FrameBuffer& operator=(const FrameBuffer& other) = delete;

    virtual void create(const FrameBufferAttachment* attachements, size_t count) = 0;

    virtual void resize(uint32_t width, uint32_t height) = 0;

    virtual void destroy() = 0;

    virtual ~FrameBuffer() {}
    
private:
    explicit FrameBuffer() noexcept = default;

};


/**
 * @brief Base class that each context provides a child of that manages the creation of a Resource
 * which holds and manages data on the CPU that will be made visible to a shader program.
 * Generally speaking, this can be thought of as a wrapper for "uniforms", although it should
 * be noted that this also suppots images/samplers (which aren't labelled as uniforms in vulkan).
 */
class Resource 
{
    friend class GLResource;
public:
    Resource(const Resource& other) = delete;
    Resource& operator=(const Resource& other) = delete;
    Resource(Resource&& other) = default;
    Resource& operator=(Resource&& other) = default;

    virtual void create(const char* name, ResourceType type, Memory memory) = 0;

    virtual void update(Memory memory) = 0;

    virtual void destroy() = 0;

    [[nodiscard]] virtual const std::string& getName() const = 0;

    [[nodiscard]] virtual const ResourceType& getType() const = 0;

    virtual ~Resource() {}
    
private:
    explicit Resource() noexcept = default;

};


/**
 * @brief Base class that each context provides a child of that manages the creation of a large
 * wrapper around a program and a number of resources that are intended to be used with that 
 * program. 
 */
class Shader   
{
    friend class GLShader;
public: 
    Shader(const Shader& other) = delete;
    Shader& operator=(const Shader& other) = delete;

    virtual void create(ProgramHandle& program, Resource* resources, size_t count) = 0;

    virtual void update(std::string name, Memory memory) = 0;

    virtual void destroy() = 0;

    virtual ~Shader() {} 
    
private:
    explicit Shader() noexcept = default;

};


/**
 * @brief Base class that each context provides a child of that manages that defines how 
 * vertex data should be interpreted (as well as providing the vertex and/or index data itself).
 */
class VertexInput 
{
    friend class GLVertexInput;
public:
    VertexInput(const VertexInput& other) = delete;
    VertexInput& operator=(const VertexInput& other) = delete;

    virtual void create(const VertexBufferHandle& buffer, const VertexLayoutHandle& layout, const IndexBufferHandle* indexBuffer) = 0;

    virtual void destroy() = 0;

    virtual ~VertexInput() {}
    
private:
    explicit VertexInput() noexcept = default;

};


/**
 * @brief Initializes the rendering framework by setting the correct graphics context from
 * which all following context calls will be made to. 
 * @note This function MUST be called before any graphics-related functions, otherwise the 
 * context will considered as null and an error will be thrown.
 */
void init(
    const GraphicsSettings& config
);


/**
 * @brief Destroys the graphics context in use and other various resources, but importantly
 * not the ones that were created and returned to the user. The intention with this framework
 * was to be provide maximum flexibility and, as such, all memory that was created by the user
 * through the various createX() function should be managed by the user.
 * @note eventhough smart pointers are returned by createX() functions, the relative destroy()
 * member function should be called on each object before it goes out of scope, which cleans
 * up the context-related reources.
 */
void shutdown();


/**
 * @brief Returns a smart pointer reference to the window (currently using GLFW).
 */
[[nodiscard]] WindowHandle& getWindow();



/**
 * @brief Creates a buffer on the GPU, fills it with the given data and returns a smart pointer
 * to the base class.
 * @note This should be used to allocate memory for vertex data.
 * @param memory The memory that the buffer will be filled with.
 * @param flags n/a for now.
 * @return A smart pointer to the base VertexBuffer class which abstracts context-related
 * operations and offers a minimal interface for the user.
 */
[[nodiscard]] VertexBufferHandle createVertexBuffer(
    Memory              memory, 
    uint32_t            flags
);


/**
 * @brief Creates a buffer on the GPU, fills it with the given data and returns a smart pointer
 * to the base class.
 * @note This should be used to allocate memory index data.
 * @param memory The memory that the buffer will be filled with.
 * @param flags n/a for now.
 * @return A smart pointer to the base IndexBuffer class which abstracts context-related
 * operations and offers a minimal interface for the user.
 */
[[nodiscard]] IndexBufferHandle createIndexBuffer(
    Memory              memory, 
    uint32_t            flags
);


/**
 * @brief Creates a buffer on the GPU, fills it with the given data and returns a smart pointer
 * to the base class.
 * @note This should be used to allocate memory uniform data.
 * @param memory The memory that the buffer will be filled with.
 * @param flags n/a for now.
 * @return A smart pointer to the base UniformBuffer class which abstracts context-related
 * operations and offers a minimal interface for the user.
 */
[[nodiscard]] UniformBufferHandle createUniformBuffer(
    Memory              memory,
    uint32_t            flags
);


/**
 * @brief Creates a shader program from the given source code.
 * @note This should be passed to a Shader object in order for draw calls to be made
 * to the appropraite pipeline.
 * @param vertPath filePath to the vertex shader code.
 * @param fragPath filePath to the fragment shader code.
 * @return A smart pointer to the base Program class which abstracts context-related
 * operations and offers a minimal interface for the user.
 */
[[nodiscard]] ProgramHandle createProgram(
    const char*         vertPath,
    const char*         fragPath
);


/**
 * @brief Creates a buffer on the GPU for texture data and defines how it should be sampled.
 * @note This is the sole object to be used for texture data and can be used in a variety
 * of different contexts (attachments for FrameBuffers or as texture data for meshes).
 * @param target texture target type (probably Texture2D).
 * @param level mip-map level for this texture (probably 0).
 * @param internalFormat number of channels for the texture data as well as the type (probably RGBA32F).
 * @param width width of the texture in pixels.
 * @param height height of the texture in pixels.
 * @param format similar to internalFormat, but only needs the number of channels (probably RGBA).
 * @param type the type specified for the internalFormat (probably Float).
 * @param nMipMaps the number of mip-maps that should be generated. If 0, then no mip-maps are generated.
 * @param sampler the sampler that will be used with this texture (defines how it should be sampled).
 * @return A smart pointer to the base Texture class which abstracts context-related
 * operations and offers a minimal interface for the user.
 */
[[nodiscard]] TextureHandle createTexture(
    TargetType              target,  
    uint32_t                level, 
    InternalFormat          internalFormat,  
    uint32_t                width,     
    uint32_t                height,    
    Format                  format,  
    ValueType               type, 
    uint32_t                nMipMaps,  
    uint32_t                flags, 
    SamplerHandle&          sampler  
);


/**
 * @brief Creates a sampler which are used with Texture instances to define how the texture
 * data should be sampled (wrapping and filter types).
 * @note One single sampler can be used with many different textures.
 * @note For the min and mag filters, if mip maps are intended to be used with the texture that this
 * sampler will be applied to, they should be set the MipMap variants, otherwise the mip maps
 * won't be used.
 * @param addressModeS the wrapping mode along the x-axis of the texture (probably ClampToEdge).
 * @param addressModeT the wrapping mode along the y-axis of the texture (probably ClampToEdge).
 * @param addressModeR the wrapping mode along the z-axis of the texture (probably ClampToEdge).
 * @param minFilter the minification filter used when texture samples don't map 1:1 to pixels (probably Linear).
 * @param magFilter the magnification filter used when texture samples don't map 1:1 to pixels (probably Linear).
 * @return A smart pointer to the base Program class which abstracts context-related
 * operations and offers a minimal interface for the user.
 */
[[nodiscard]] SamplerHandle createSampler(
    SamplerAddressMode         addressModeS,
    SamplerAddressMode         addressModeT,
    SamplerAddressMode         addressModeR,
    SamplerFilterMode          minFilter,
    SamplerFilterMode          magFilter
);


/**
 * @brief Creates an off-screen rendering buffer with the attachments passed in.
 * In order to actually draw to a framebuffer, @ref begin must be called with a smart pointer
 * (the return value of this function) to a FrameBuffer instance. 
 * @param attachments a raw pointer to the first of an array of attachments (likely just the single color attachment).
 * @param count the number of attachements passed.
 * @return A smart pointer to the base FrameBuffer class which abstracts context-related
 * operations and offers a minimal interface for the user.
 */
[[nodiscard]] FrameBufferHandle createFrameBuffer(
    const FrameBufferAttachment*   attachments,
    size_t                         count
);


/**
 * @brief Creates a buffer on the GPU and fills it with the data passed in with @ref memory.
 * These should be constructed to hold and bind "uniform" data to Shader instances, with "uniform"
 * here meaning any of the types listed in @ref type.
 * @param name the name of the resource which will act as a key for a resource map that can be queried after construction (remember this).
 * @param type the type of the resource of which all available ones are listed in the ResourceType enum.
 * @param memory the memory of the data that you wish to be made available to the shader program.
 * @return A smart pointer to the base Resource class which abstracts context-related
 * operations and offers a minimal interface for the user.
 */
[[nodiscard]] ResourceHandle createResource(
    std::string        name,
    ResourceType       type,
    Memory             memory
);


/**
 * @brief Creates a Shader instance that encapsulates a single Program and many Resource instances to define
 * a pipeline that can be submitted with a vertex input instance to draw graphics to the screen. 
 * @param program a raw pointer to the Program.
 * @param resources a raw pointer to the first of an array of Resources.
 * @param count the number of resources passed.
 * @return A smart pointer to the base Shader class which abstracts context-related
 * operations and offers a minimal interface for the user.
 */
[[nodiscard]] ShaderHandle createShader(
    const ProgramHandle&        program,
    ResourceHandle*             resources,
    size_t                      count
);


/**
 * @brief Creates a VertexInput instance which encapsulates the GPU buffers that will be used 
 * to hold vertex data, as well as the layout that describes how that vertex data should be interpreted
 * by the shader program.
 * @param vBuffer the VertexBuffer instance that holds a handle to the GPU vertex buffer.
 * @param layout the VertexLayout that describes how this vertex buffer should be interpreted.
 * @param iBuffer the indexBuffer associated with the VertexBuffer instance.
 * @return A smart pointer to the base VertexInput class which abstracts context-related
 * operations and offers a minimal interface for the user.
 */
[[nodiscard]] VertexInputHandle createVertexInput(
    const VertexBufferHandle&   vBuffer,
    const VertexLayoutHandle&   layout,
    const IndexBufferHandle*    iBuffer
);


/**
 * @brief Binds all appropriate resources and makes a draw command to the GPU. 
 * @param input the VertexInput instance which holds the vertex data to draw rasterize.
 * @param shader the Shader instance that holds the Program and Resources to be used with the
 * the draw command.
 */
void submit(
    const VertexInputHandle&  input, 
    const ShaderHandle&       shader
);



}


#endif