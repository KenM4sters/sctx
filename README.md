## Sandbox


## Key Concepts

- Shaders
- Textures
- Samplers
- Buffers
- Framebuffers




## Desired Example Code

```

auto texture = sctx::TextureBuilder::new()
    .from_url("x.png")
    .mipmaps(5)
    .build();

auto model = sctx::ModelBuilder::new()
    .from_gltf("x.gltf)
    .build();




```