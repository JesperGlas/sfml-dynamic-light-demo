uniform float u_ambiance;
uniform sampler2D u_currentTexture;
uniform sampler2D u_lightmap;

void main()
{
    // lookup the pixel in the texture
    vec4 px_color = texture2D(u_currentTexture, gl_TexCoord[0].xy);
    vec4 light = texture2D(u_lightmap, gl_TexCoord[0].xy);

    // multiply it by the color
    gl_FragColor = px_color * max(clamp(light, 0.f, 1.f), u_ambiance);
}