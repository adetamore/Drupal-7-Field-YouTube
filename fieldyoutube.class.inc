<?php
// $Id$

/**
 * @file
 * Youtube field main class, for parsing youtube links and embeding media
 */

class YouTube {

  private $youtubeId = NULL;


  /**
  * Constructor
  *
  * This is the default constructor which accepts YouTube URL.
  */
  function __construct($url = NULL) {
    if ($url != NULL) {
      $this->youtubeId = $this->parseURL($url);
    }
  }


  /**
  * Set YouTube ID
  *
  * This method sets YouTube ID.
  * Returns TRUE if the ID is ok, and FALSE if not.
  */
  public function setID($id) {
    if (preg_match('/([A-Za-z0-9_-]+)/', $url, $matches)) {
      $this->youtubeId = $id;
      return TRUE;
    }
    else
      return FALSE;
  }


  /**
  * Get YouTube ID
  *
  * This method returns YouTube video ID. Otherwise returns NULL as set in constructor.
  */
  public function getID() {
    return $this->youtubeId;
  }


  /**
  * Parse YouTube URL and return video ID.
  *
  * This method strips YouTube ID from URL. Otherwise returns NULL.
  */
  public function parseURL($url) {
    if (preg_match('/watch\?v\=([A-Za-z0-9_-]+)/', $url, $matches))
      return $matches[1];
    else
      return FALSE;
  }


	/**
	* Get YouTube video HTML embed code
	*
	* This method returns HTML code which is used to embed YouTube video in node
	*/
	public function EmbedVideo($width = 425, $height = 344, $url = NULL, $hd = 1, $ap = 1) {
		if ($url == NULL)
				$videoid = $this->youtubeId;
		else {
				$videoid = $this->parseURL($url);
				if (!$videoid) $videoid = $url;
		}
		
		$output = '<iframe width="'.$width.'" height="'.$height.'" id="player" src="http://www.youtube.com/embed/'.$videoid.'?wmode=transparent&amp;autohide=1&amp;egm=0&amp;hd=1&amp;iv_load_policy=3&amp;modestbranding=1&amp;rel=0&amp;showinfo=0&amp;showsearch=0" frameborder="0" allowfullscreen></iframe>';
		
		
		//<iframe width="464" height="261" frameborder="0" allowfullscreen="" src="http://www.youtube-nocookie.com/embed/rZ2dIVB1vmk?wmode=transparent&amp;autohide=1&amp;egm=0&amp;hd=1&amp;iv_load_policy=3&amp;modestbranding=1&amp;rel=0&amp;showinfo=0&amp;showsearch=0"></iframe>
		return $output;
		
		
		//return ''
		//	.	'<object width="' . $width . '" height="' . $height . '">'
		//	.	'<param name="movie" value="http://www.youtube.com/v/' . $videoid . '?rel=0&fs=1&loop=0&autoplay='.$ap.'&hd=' . $hd . '&showinfo=0"></param>'
		//	.	'<param name="wmode" value="opaque"></param>'
		//	.	'<param name="allowFullScreen" value="TRUE">'
		//	.	'<embed src="http://www.youtube.com/v/' . $videoid . '?rel=0&fs=1&loop=0&autoplay='.$ap.'&hd=' . $hd . '&showinfo=0" allowfullscreen="TRUE" type="application/x-shockwave-flash" wmode="opaque" width="' . $width . '" height="' . $height . '"></embed></object>';
			// TODO: browser detect
	}


	/**
	* Get URL of YouTube video thumbnail
	*
	* This method returns URL of YouTube video thumbnail. It can get one of three defined by YouTube
	*/
	public function GetImg($url = NULL, $imgid = 1) {
		if ($url == NULL)
			$videoid = $this->youtubeId;
		else {
			$videoid = $this->parseURL($url);
			if (!$videoid) $videoid = $url;
		}
		return "http://img.youtube.com/vi/".$videoid."/".$imgid.".jpg";
	}


	/**
	* Get YouTube screenshot HTML code
	*
	* This method returns HTML code which is used to embed YouTube video thumbnail in page
	*/
	public function ShowImg($url = NULL, $imgid = 1, $alt = 'Video screenshot') {
		return '<img src="' . $this->GetImg($url, $imgid) . '" alt="' . $alt . '" title="' . $alt . '" />';
	}

}

