uniform sampler2D objectMap;
uniform sampler2D shadowMap;

void main()
{
    // lookup the pixel in the texture
    vec4 pixel = texture2D(objectMap, gl_TexCoord[0].xy);

    // multiply it by the color
    gl_FragColor = gl_Color * pixel;
}