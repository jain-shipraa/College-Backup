
package q7;
import java.io.*;
import javax.servlet.jsp.*;
import javax.servlet.jsp.tagext.*;
/**
 *
 * @author pc4
 */
public class choco extends SimpleTagSupport{
    private String texture;
    
    public void setTexture(String t)
    {
        this.texture=t;
    }
    
    public void doTag() throws IOException
    {
        JspWriter Out=getJspContext().getOut();
        if(texture=="Chewy")
        {
            Out.println("FiveStar, BarOne");
        }
        else if(texture=="Crunchy")
        {
            Out.println("Munch, KitKat");
        }
            
    }
}
